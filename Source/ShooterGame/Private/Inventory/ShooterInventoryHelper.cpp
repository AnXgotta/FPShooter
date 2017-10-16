// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterInventoryHelper.h"


UShooterInventoryHelper::UShooterInventoryHelper() {
	static::ConstructorHelpers::FObjectFinder<UDataTable> WeaponInfoTable(TEXT("/Game/DataTables/WeaponInfo_DataTable.WeaponInfo_DataTable"));
	static::ConstructorHelpers::FObjectFinder<UDataTable> WeaponUITable(TEXT("/Game/DataTables/WeaponUI_DataTable.WeaponUI_DataTable"));

}

FShooterInventoryItem GetWeaponInventoryInfo(FName WeaponId) {

	//const FShooterInventoryItem Item = WeaponInfoTable->

	return FShooterInventoryItem();
}
