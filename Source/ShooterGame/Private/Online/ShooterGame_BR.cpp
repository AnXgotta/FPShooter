// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "WeaponDataTable.h"
#include "ShooterGame_BR.h"


AShooterGame_BR::AShooterGame_BR() {

	ConstructorHelpers::FObjectFinder<UDataTable> WeaponInfoTable(TEXT("DataTable'/Game/DataTables/WeaponInfo_DataTable.WeaponInfo_DataTable'"));

	if (WeaponInfoTable.Object != NULL) {
		WeaponInfoDT = WeaponInfoTable.Object;
	}

}


FWeaponData AShooterGame_BR::Data_GetWeaponDefaultData(FString WeaponId) {
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString(TEXT("StartWeapon Info Table Search")));
	if (WeaponInfoDT == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString(TEXT("Server DataTable not found")));
		return FWeaponData();
	}

	const FWeaponDataTable* Item = WeaponInfoDT->FindRow<FWeaponDataTable>(FName(*WeaponId), FString(TEXT("")));

	if (Item == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString(TEXT("Server DataTable Row not found")));
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
