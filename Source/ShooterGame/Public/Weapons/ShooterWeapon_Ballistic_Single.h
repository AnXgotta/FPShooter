// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/ShooterWeapon_Ballistic.h"
#include "ShooterWeapon_Ballistic_Single.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterWeapon_Ballistic_Single : public AShooterWeapon_Ballistic
{
	GENERATED_BODY()

		AShooterWeapon_Ballistic_Single();

		/** [local] weapon specific fire implementation */
		virtual void FireWeapon() override;
	
};
