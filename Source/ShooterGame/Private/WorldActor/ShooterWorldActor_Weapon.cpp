// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActor_Weapon.h"



AShooterWorldActor_Weapon::AShooterWorldActor_Weapon() {
	// outliner layer for highlighting actor
	Mesh->SetCustomDepthStencilValue(1);
}

bool AShooterWorldActor_Weapon::OnPickUp_Implementation(AShooterPlayerController* PlayerController) {
	if (PlayerController) {
		PlayerController->OnItemPickUp(this);
	}
	return true;
}

bool AShooterWorldActor_Weapon::OnPutDown_Implementation(AShooterPlayerController* PlayerController) {
	if (PlayerController) {
		PlayerController->OnItemPutDown(this);
	}
	return true;
}


bool AShooterWorldActor_Weapon::OnActorInteracted_Implementation(APlayerController* PlayerController) {

	return true;
}

bool AShooterWorldActor_Weapon::BeginOutlineFocus_Implementation() {
	Mesh->SetRenderCustomDepth(true);
	return true;
}

bool AShooterWorldActor_Weapon::AShooterWorldActor_Weapon::EndOutlineFocus_Implementation() {
	Mesh->SetRenderCustomDepth(false);
	return true;
}

bool AShooterWorldActor_Weapon::GetIsActorInteractable_Implementation() {
	return true;
}

FString AShooterWorldActor_Weapon::GetInteractActionText_Implementation() {
	return FString(TEXT("Interact"));
}