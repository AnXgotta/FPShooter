// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterTypes.h"
#include "Components/ActorComponent.h"
#include "ShooterInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERGAME_API UShooterInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

		float InventoryWeight;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		float InventoryMaxWeight;

		TArray<FShooterInventoryItem> Inventory;

public:	
	// Sets default values for this component's properties
	UShooterInventoryComponent();

protected:

	void InitializeInventory(float InventoryWeight);

public:	
	
	FShooterInventoryItem* GetInventoryItem(FName& DesiredItemID);

	bool SetInventoryItem(FShooterInventoryItem InventoryItem);

	bool ClearInventoryItem(FName& DesiredItemID);

	FORCEINLINE TArray<FShooterInventoryItem> GetInventory() { return Inventory; };
	
};
