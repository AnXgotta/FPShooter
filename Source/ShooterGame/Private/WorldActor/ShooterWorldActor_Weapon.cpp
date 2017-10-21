// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWorldActor_Weapon.h"



AShooterWorldActor_Weapon::AShooterWorldActor_Weapon() {
	ItemType = EShooterItemType::Weapon;
	CustomOutlineDepthValue = 2;
}