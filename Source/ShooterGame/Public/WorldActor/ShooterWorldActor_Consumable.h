// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldActor/ShooterWorldActorBase.h"
#include "ShooterWorldActor_Consumable.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterWorldActor_Consumable : public AShooterWorldActorBase
{
	GENERATED_BODY()
	
		/** weapon data */
		UPROPERTY(EditDefaultsOnly, Category = Config)
		FText ConsumableNameId;
	
public:

	AShooterWorldActor_Consumable();

	FORCEINLINE FText GetConsumableNameId() { return ConsumableNameId; }

	
};
