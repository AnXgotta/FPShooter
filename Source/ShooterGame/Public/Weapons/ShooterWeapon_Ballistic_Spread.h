// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/ShooterWeapon_Ballistic.h"
#include "ShooterWeapon_Ballistic_Spread.generated.h"

USTRUCT()
struct FBallisticSpreadWeaponData
{
	GENERATED_USTRUCT_BODY()

		/** muzzle velocity (M/s) */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		int32 PelletCount;

	/** defaults */
	FBallisticSpreadWeaponData()
	{
		PelletCount = 12;
	}
};

UCLASS()
class SHOOTERGAME_API AShooterWeapon_Ballistic_Spread : public AShooterWeapon_Ballistic
{
	GENERATED_BODY()

public:

		AShooterWeapon_Ballistic_Spread();

protected:

	/** weapon config */
	UPROPERTY(EditDefaultsOnly, Category = Config)
		FBallisticSpreadWeaponData SpreadConfig;

		/** [local] weapon specific fire implementation */
		virtual void FireWeapon() override;


	
};
