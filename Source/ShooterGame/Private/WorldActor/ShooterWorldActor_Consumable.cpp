// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActor_Consumable.h"



AShooterWorldActor_Consumable::AShooterWorldActor_Consumable() {
	ItemType = EShooterItemType::Consumable;
	CustomOutlineDepthValue = 4;
}


bool AShooterWorldActor_Consumable::OnPickUp_Implementation(AShooterCharacter* Player) {
	if (Player) {
		Player->OnItemPickUp("AK47");
	}
	return true;
}

bool AShooterWorldActor_Consumable::OnPutDown_Implementation() {

	return true;
}

bool AShooterWorldActor_Consumable::OnConsumeItem_Implementation(AShooterCharacter* Player) {

	return true;
}

void AShooterWorldActor_Consumable::OnWasInteracted() {
	Super::OnWasInteracted();
	// play sounds or effects on clients and destroy or whatever
	// PLAY SOUNDS AND HANDLE OTHER SHIT ON OVERRIDED METHOD
}
