// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "WeaponDataTable.h"
#include "WeaponUIDataTable.h"
#include "ConsumableDataTable.h"
#include "ConsumableUIDataTable.h"
#include "ShooterGame_BR.h"


AShooterGame_BR::AShooterGame_BR() {

}


FWeaponData AShooterGame_BR::Data_GetWeaponDefaultData(FString WeaponId) {

	if (WeaponInfoDT == nullptr) {
		return FWeaponData();
	}

	const FWeaponDataTable* Item = WeaponInfoDT->FindRow<FWeaponDataTable>(FName(*WeaponId), FString(TEXT("")));

	if (Item == nullptr) {
		return FWeaponData();
	}

	FWeaponData WeapData = FWeaponData();

	WeapData.SpawnClass = Item->SpawnClass;
	WeapData.MaxAmmo = Item->MaxAmmo;
	WeapData.AmmoPerClip = Item->AmmoPerClip;
	WeapData.InitialClips = Item->InitialClips;
	WeapData.TimeBetweenShots = Item->TimeBetweenShots;
	WeapData.NoAnimReloadDuration = Item->NoAnimReloadDuration;
	WeapData.bSingleFire = Item->bSingleFire;
	WeapData.Weight = Item->Weight;
	WeapData.BallisticData = FBallisticWeaponData();
	WeapData.BallisticData.MuzzleVelocity = Item->MuzzleVelocity;
	WeapData.BallisticData.VerticalRotation = Item->VerticalRotation;
	WeapData.BallisticData.HitDamage = Item->HitDamage;
	WeapData.BallisticData.DamageType = Item->DamageType;
	WeapData.BallisticData.WeaponSpread = Item->WeaponSpread;
	WeapData.BallisticData.TargetingSpreadMod = Item->TargetingSpreadMod;
	WeapData.BallisticData.FiringSpreadIncrement = Item->FiringSpreadIncrement;
	WeapData.BallisticData.FiringSpreadMax = Item->FiringSpreadMax;
	WeapData.BallisticData.ClientSideHitLeeway = Item->ClientSideHitLeeway;
	WeapData.BallisticData.AllowedViewDotHitDir = Item->AllowedViewDotHitDir;
	WeapData.RecoilData = FWeaponRecoil();
	WeapData.RecoilData.VerticalDisplacement = Item->VerticalDisplacement;
	WeapData.RecoilData.HorizontalDisplacementRangeMaxAbsoluteValue = Item->HorizontalDisplacementRangeMaxAbsoluteValue;
	WeapData.RecoilData.bDisplacementOnSingleShot = Item->bDisplacementOnSingleShot;
	WeapData.RecoilData.bDisplacementOnFullAutoShot = Item->bDisplacementOnFullAutoShot;

	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString(TEXT("StartWeapon Info Table Search")));
	return WeapData;
}

FShooterInventoryItem AShooterGame_BR::Data_GetWeaponInventoryItem(FString ItemId) {

	FShooterInventoryItem NewItem;

	if (WeaponUIDT == nullptr) {
		return NewItem;
	}

	const FWeaponUIDataTable* Item = WeaponUIDT->FindRow<FWeaponUIDataTable>(FName(*ItemId), FString(TEXT("")));

	if (Item == nullptr) {
		return NewItem;
	}

	NewItem.Icon = Item->Icon;
	NewItem.ID = *(Item->ItemId.ToString());
	NewItem.Name = *(Item->Title.ToString());
	NewItem.Description = Item->Description.ToString();
	NewItem.Weight = Item->Weight;
	NewItem.bIsStackable = Item->bIsStackable;
	NewItem.MaxStackable = Item->MaxStackable;

	NewItem.InteractableType = EShooterInteractableType::Weapon;

	return NewItem;
}

FShooterInventoryItem AShooterGame_BR::Data_GetItemInventoryItem(FString ItemId) {
	
	FShooterInventoryItem NewItem;

	if (ConsumableUIDT == nullptr) {
		return NewItem;
	}

	const FConsumableUIDataTable* Item = ConsumableUIDT->FindRow<FConsumableUIDataTable>(FName(*ItemId), FString(TEXT("")));

	if (Item == nullptr) {
		return NewItem;
	}

	
	NewItem.Icon = Item->Icon;
	NewItem.ID = *(Item->ItemId.ToString());
	NewItem.Name = *(Item->Title.ToString());
	NewItem.Description = Item->Description.ToString();
	NewItem.Weight = Item->Weight;
	NewItem.bIsStackable = Item->bIsStackable;
	NewItem.MaxStackable = Item->MaxStackable;

	const FConsumableDataTable* ItemInfo = ConsumableDT->FindRow<FConsumableDataTable>(FName(*ItemId), FString(TEXT("")));

	if (ItemInfo == nullptr) {
		return NewItem;
	}

	NewItem.InteractableType = EShooterInteractableType::Consumable;
	NewItem.ConsumableType = ItemInfo->ConsumableType;

	return NewItem;
}