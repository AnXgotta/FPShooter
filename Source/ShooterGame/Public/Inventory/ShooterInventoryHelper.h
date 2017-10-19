// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ShooterTypes.h"
#include "ShooterInventoryHelper.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterInventoryHelper : public UObject
{
	GENERATED_BODY()

public:

	UShooterInventoryHelper();

	UDataTable* WeaponInfoDT;
	UDataTable* WeaponUIInfoDT;

	FWeaponData GetWeaponInventoryInfo(FString WeaponId);


};
