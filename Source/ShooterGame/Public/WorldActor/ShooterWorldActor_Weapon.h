// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterItemPUPDInterface.h"
#include "ShooterInteractableActorInterface.h"
#include "WorldActor/ShooterWorldActorBase.h"
#include "ShooterWorldActor_Weapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterWorldActor_Weapon : public AShooterWorldActorBase
{
	GENERATED_BODY()

	/** attachment data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	TArray<FText> AttachmentNameIds;

public:

	AShooterWorldActor_Weapon();

	FORCEINLINE TArray<FText> GetAttachmentNameIds() { return AttachmentNameIds; }


};
