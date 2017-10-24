// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldActor/ShooterWorldActorBase.h"
#include "ShooterWorldActor_Weapon.generated.h"

/**
 *
 */
UCLASS()
class SHOOTERGAME_API AShooterWorldActor_Weapon : public AShooterWorldActorBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	/** weapon data */
	FWeaponData WeaponConfig;

	/** attachment data */
	TArray<FText> AttachmentNameIds;

public:

	AShooterWorldActor_Weapon();

	UFUNCTION()
	virtual void OnWasInteracted() override;

	FORCEINLINE FWeaponData& GetWeaponData() { return WeaponConfig; }
	FORCEINLINE TArray<FText> GetAttachmentNameIds() { return AttachmentNameIds; }


};
