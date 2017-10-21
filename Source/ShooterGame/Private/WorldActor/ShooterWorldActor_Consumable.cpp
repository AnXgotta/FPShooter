// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActor_Consumable.h"



AShooterWorldActor_Consumable::AShooterWorldActor_Consumable() {
	ItemType = EShooterItemType::Consumable;
	CustomOutlineDepthValue = 4;
}

