// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterContainerActor.h"

// Sets default values
AShooterContainerActor::AShooterContainerActor()
{
	InventoryComponent = CreateDefaultSubobject<UShooterInventoryComponent>(TEXT("InventoryComponent"));

}

void AShooterContainerActor::BeginPlay()
{
	Super::BeginPlay();
	if (Role == ROLE_Authority) {
		InitializeInventory();
	}

}

void AShooterContainerActor::InitializeInventory() {
	InventoryComponent->InitializeInventory(ContainerInfo.MaxWeight);
}

bool AShooterContainerActor::OnActorUsed_Implementation(APlayerController* PlayerController) {
	if (Role != ROLE_Authority) {
		return true;
	}

	if (GetIsActorUsable_Implementation()) {
		// cas PlayerController to Inventory Player Controller
	}

	//InventoryComponent->Load
	return true;
}

FShooterInventoryContainer AShooterContainerActor::GetContainerProperties_Implementation() {
	return ContainerInfo;
}

UShooterInventoryComponent* AShooterContainerActor::GetContainerInventory_Implementation() {
	return InventoryComponent;
}

TArray<APlayerState*> AShooterContainerActor::GetPlayersViewing_Implementation() {
	return PlayersViewing;
}

bool AShooterContainerActor::CanStoreItems_Implementation() {
	return true;
}


bool AShooterContainerActor::ContainerLooted_Implementation() {
	return true;
}
