// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActor_Weapon.h"



AShooterWorldActor_Weapon::AShooterWorldActor_Weapon() {
	ItemType = EShooterItemType::Weapon;
	CustomOutlineDepthValue = 2;
}


bool AShooterWorldActor_Weapon::OnPickUp_Implementation(AShooterCharacter* Player) {
	if (Player) {
		if (Player->OnPickupWeapon(ItemNameId, AttachmentNameIds)) {
			Destroy();
			return true;
		}
	}
	return false;
}

bool AShooterWorldActor_Weapon::OnPutDown_Implementation() {

	return true;
}

void AShooterWorldActor_Weapon::OnWasInteracted() {
	Super::OnWasInteracted();
	// play sounds or effects on clients and destroy or whatever
	// PLAY SOUNDS AND HANDLE OTHER SHIT ON OVERRIDED METHOD
}

bool AShooterWorldActor_Weapon::OnActorInteracted_Implementation(AShooterCharacter* Player) {
	GEngine->AddOnScreenDebugMessage(-1, 3.0, FColor::Green, FString(TEXT("Server Interacted Weapon")));
	Super::OnActorInteracted_Implementation(Player);
	return true;
}