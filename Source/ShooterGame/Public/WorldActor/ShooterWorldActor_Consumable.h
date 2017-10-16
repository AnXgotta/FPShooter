// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldActor/ShooterWorldActorBase.h"
#include "ShooterWorldActor_Consumable.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterWorldActor_Consumable : public AShooterWorldActorBase, public IShooterItemPUPDInterface, public IShooterItemConsumeInterface
{
	GENERATED_BODY()
	
		/** weapon data */
		UPROPERTY(EditDefaultsOnly, Category = Config)
		FText ConsumableNameId;
	
public:

	AShooterWorldActor_Consumable();

	FORCEINLINE FText GetConsumableNameId() { return ConsumableNameId; }

	UFUNCTION()
		virtual void OnWasInteracted() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnPickUp(AShooterCharacter* Player);
	virtual bool OnPickUp_Implementation(AShooterCharacter* Player) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnPutDown();
	virtual bool OnPutDown_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnConsumeItem(AShooterCharacter* Player);
	virtual bool OnConsumeItem_Implementation(AShooterCharacter* Player) override;
	
};
