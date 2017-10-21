// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActor_Consumable.h"



AShooterWorldActor_Consumable::AShooterWorldActor_Consumable() {
	InteractableType = EShooterInteractableType::Consumable;
	CustomOutlineDepthValue = 4;
}

