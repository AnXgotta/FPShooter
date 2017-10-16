// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActorBase.h"


// Sets default values
AShooterWorldActorBase::AShooterWorldActorBase()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(COLLISION_INTERACTABLE, ECollisionResponse::ECR_Block);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	bWasInteracted = false;
	CustomOutlineDepthValue = 1;
}

// Called when the game starts or when spawned
void AShooterWorldActorBase::BeginPlay(){
	Super::BeginPlay();
	Mesh->SetCustomDepthStencilValue(CustomOutlineDepthValue);
}

// Called every frame
void AShooterWorldActorBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

bool AShooterWorldActorBase::OnActorInteracted_Implementation(AShooterCharacter* Player) {
	// server only
	GEngine->AddOnScreenDebugMessage(-1, 3.0, FColor::Green, FString(TEXT("Server Interacted Base")));
	return true;
}

bool AShooterWorldActorBase::BeginOutlineFocus_Implementation() {
	Mesh->SetRenderCustomDepth(true);
	return true;
}

bool AShooterWorldActorBase::EndOutlineFocus_Implementation() {
	Mesh->SetRenderCustomDepth(false);
	return true;
}

bool AShooterWorldActorBase::GetIsActorInteractable_Implementation() {
	return true;
}

FString AShooterWorldActorBase::GetInteractActionText_Implementation() {
	return FString(TEXT("Interact"));
}


void AShooterWorldActorBase::OnRep_WasInteracted() {
	// replicated to clients to do whatever shit... sounds or destroy self or whatever
	OnWasInteracted();
}

void AShooterWorldActorBase::OnWasInteracted() {
	// play sounds or effects on clients and destroy or whatever
	// PLAY SOUNDS AND HANDLE OTHER SHIT ON OVERRIDED METHOD
}

void AShooterWorldActorBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AShooterWorldActorBase, bWasInteracted);
}
