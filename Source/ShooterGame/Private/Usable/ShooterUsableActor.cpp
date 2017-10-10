// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterUsableActor.h"


// Sets default values
AShooterUsableActor::AShooterUsableActor()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	bReplicates = true;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterUsableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterUsableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AShooterUsableActor::GetIsActorUsable_Implementation() {
	return bIsUsable;
}

bool AShooterUsableActor::OnActorUsed_Implementation(APlayerController* PlayerController) {
	if (Role == ROLE_Authority) {
		bWasUsed = !bWasUsed;
		return true;
	}
	else {
		return false;
	}
}

FString AShooterUsableActor::GetUseActionText_Implementation() {
	return Action.ToString() + " " + Name.ToString();
}

bool AShooterUsableActor::BeginOutlineFocus_Implementation() {
	StaticMesh->SetRenderCustomDepth(true);
	return true;
}

bool AShooterUsableActor::EndOutlineFocus_Implementation() {
	StaticMesh->SetRenderCustomDepth(false);
	return true;
}

void AShooterUsableActor::OnRep_WasUsed() {
	OnWasUsed();
}

bool AShooterUsableActor::OnWasUsed() {
	if (UsedSound) {
		UGameplayStatics::SpawnSoundAttached(UsedSound, RootComponent);
	}
	return true;
}

void AShooterUsableActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AShooterUsableActor, bIsUsable);

}


