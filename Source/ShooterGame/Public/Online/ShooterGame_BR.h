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
	
	
		UPROPERTY()
		UDataTable* WeaponInfoDT;

	
	
public:

	AShooterGame_BR();

	UFUNCTION()
		FWeaponData Data_GetWeaponDefaultData(FString WeaponId);

};
