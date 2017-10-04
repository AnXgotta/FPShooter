// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWeapon_Ballistic.h"
#include "ShooterBallisticTrace.h"


// Sets default values
AShooterBallisticTrace::AShooterBallisticTrace()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	TraceStart = CreateDefaultSubobject<USceneComponent>(TEXT("TraceStart"));
	TraceStart->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	TraceEnd = CreateDefaultSubobject<USceneComponent>(TEXT("TraceEnd"));
	TraceEnd->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

	BallisticTraceLifetime = 10.0f;
	BallisticTraceFrequency = 0.01f;
}

// Called when the game starts or when spawned
void AShooterBallisticTrace::BeginPlay()
{
	Super::BeginPlay();
	StartBallisticTrace();
}

// Called every frame
void AShooterBallisticTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AShooterBallisticTrace::InitializeValues(const float MuzzleVelocity) {
	MVelocity = MuzzleVelocity;
}

void AShooterBallisticTrace::StartBallisticTrace() {

	Origin = this->RootComponent->GetComponentLocation();

	TraceStart->SetRelativeLocation(FVector::ZeroVector);
	TraceEnd->SetRelativeLocation(FVector::ZeroVector);

	// get current game time in millis
	TraceStartTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());

	// get total angle from world coords and get x and z velocity
	AimAngle = this->RootComponent->GetComponentRotation().Pitch;

	XVelocity = MVelocity * FMath::Cos(FMath::DegreesToRadians(AimAngle));
	ZVelocity = MVelocity * FMath::Sin(FMath::DegreesToRadians(AimAngle));

	this->RootComponent->SetRelativeRotation(FRotator(0.0f, this->RootComponent->GetComponentRotation().Yaw, this->RootComponent->GetComponentRotation().Roll));


	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("AimAngle: %f | Velocity (X: %f, Z: %f)"), AimAngle, XVelocity, ZVelocity));

	UWorld* World = GetWorld();
	if (World) {
		World->GetTimerManager().SetTimer(BallisticTraceTimerHandle, this, &AShooterBallisticTrace::PerformBallisticTrace, BallisticTraceFrequency, true, 0.0f);
	}
}

void AShooterBallisticTrace::PerformBallisticTrace() {

		const float CurrentTraceTime = UGameplayStatics::GetRealTimeSeconds(GetWorld()) - TraceStartTime;
		
		const float DeltaX = XVelocity * CurrentTraceTime;
		const float DeltaZ = (ZVelocity * CurrentTraceTime) - (490.0f * FMath::Square(CurrentTraceTime));
		
		TraceEnd->SetRelativeLocation(FVector(DeltaX, 0.0f, DeltaZ));
			
		const FHitResult Impact = BallisticsTrace(TraceStart->GetComponentLocation(), TraceEnd->GetComponentLocation());

			if (Impact.GetActor()) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Trace Hit"));
				UWorld* World = GetWorld();
				if (World) {
					World->GetTimerManager().ClearTimer(BallisticTraceTimerHandle);
				}
				HandleImpact(Impact);
			}
			else {
				TraceStart->SetWorldLocation(TraceEnd->GetComponentLocation());
			}

		if (CurrentTraceTime >= BallisticTraceLifetime) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Trace Destroyed via Time limit"));
			UWorld* World = GetWorld();
			if (World) {
				World->GetTimerManager().ClearTimer(BallisticTraceTimerHandle);
			}
			Destroy();
		}
	
}

	FHitResult AShooterBallisticTrace::BallisticsTrace(const FVector& StartTrace, const FVector& EndTrace) const
	{

		DrawDebugLine(
			GetWorld(),
			StartTrace,
			EndTrace,
			FColor(255, 0, 0),
			true, -1, 0,
			2
		);

		// Perform trace to retrieve hit info
		FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(WeaponTrace), true, Instigator);
		TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_WEAPON, TraceParams);

		return Hit;
	}


	void AShooterBallisticTrace::HandleImpact(const FHitResult& Impact) {
		AShooterWeapon_Ballistic* OwningWeapon = Cast<AShooterWeapon_Ballistic>(this->GetOwner());
		
		if (OwningWeapon) {
			OwningWeapon->OnBulletTraceHit(Origin, Impact);
		}
		Destroy();
	}
