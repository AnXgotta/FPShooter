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

		int32 Amount;
	
public:

	AShooterWorldActor_Consumable();

	UFUNCTION()
	virtual void OnWasInteracted() override;

	FORCEINLINE int32 GetAmount() 
	{
		return Amount;
	}

	FORCEINLINE void SetAmount(int32 NewAmount)
	{
		Amount = NewAmount;
	}
	
};
