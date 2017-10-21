// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterWeapon.h"
#include "ShooterTypes.h"
#include "Components/ActorComponent.h"
#include "ShooterInventoryComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERGAME_API UShooterInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	TArray<FShooterInventoryItem> Inventory;
	


public:	
	// Sets default values for this component's properties
	UShooterInventoryComponent();

	float InventoryWeight;
	float InventoryMaxWeight;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeInventory(float NewInventoryMaxWeight);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FShooterInventoryItem GetInventoryItem(FName& DesiredItemID);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool SetInventoryItem(FShooterInventoryItem InventoryItem);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool ClearInventoryItem(FName& DesiredItemID);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void ModifyInventoryMaxSize(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool IsSpaceFor(float Weight);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FShooterInventoryItem> GetInventory();


	


	
};
