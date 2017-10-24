// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterGame_BR.h"
#include "ShooterWorldActor_Weapon.h"



AShooterWorldActor_Weapon::AShooterWorldActor_Weapon() {
	InteractableType = EShooterInteractableType::Weapon;
	CustomOutlineDepthValue = 2;
}

void AShooterWorldActor_Weapon::BeginPlay() {
	Super::BeginPlay();

	// can only access game mode on the server
	// get weapon info from data table
	if (Role == ROLE_Authority) {
		UWorld* World = GetWorld();
		if (World) {
			AShooterGame_BR* Game = Cast<AShooterGame_BR>(World->GetAuthGameMode());
			if (Game) {
				WeaponConfig = Game->Data_GetWeaponDefaultData(ItemNameId);
			}
		}
	}
}

void AShooterWorldActor_Weapon::OnWasInteracted() {
	Super::OnWasInteracted();
	Destroy();
}