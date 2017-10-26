// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameMode.h"
#include "ShooterGame_BR.generated.h"

/**
 *
 */
UCLASS()
class SHOOTERGAME_API AShooterGame_BR : public AShooterGameMode
{
	GENERATED_BODY()


		UPROPERTY(EditDefaultsOnly, Category = Defaults)
		UDataTable* WeaponInfoDT;

	UPROPERTY(EditDefaultsOnly, Category=Defaults)
		UDataTable* WeaponUIDT;

	UPROPERTY(EditDefaultsOnly, Category = Defaults)
		UDataTable* ConsumableDT;

	UPROPERTY(EditDefaultsOnly, Category = Defaults)
		UDataTable* ConsumableUIDT;



public:

	AShooterGame_BR();

	UFUNCTION()
		FWeaponData Data_GetWeaponDefaultData(FString WeaponId);

	UFUNCTION()
		FShooterInventoryItem Data_GetWeaponInventoryItem(FString ItemId);

	UFUNCTION()
		FShooterInventoryItem Data_GetItemInventoryItem(FString ItemId);

};
