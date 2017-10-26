// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterWeapon.h"
#include "ShooterTypes.h"
#include "Components/ActorComponent.h"
#include "ShooterInventoryComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTERGAME_API UShooterInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

		UPROPERTY(ReplicatedUsing = OnRep_Inventory)
		TArray<FShooterInventoryItem> Inventory;

	UPROPERTY(ReplicatedUsing = OnRep_Proximity)
		TArray<FShooterInventoryItem> Proximity;

	UFUNCTION()
		void OnRep_Inventory();

	UFUNCTION()
		void OnRep_Proximity();


public:
	// Sets default values for this component's properties
	UShooterInventoryComponent();

	UPROPERTY(Replicated)
	float InventoryWeight;
	UPROPERTY(Replicated)
	float InventoryMaxWeight;

	UFUNCTION()
		void AddItemsToProximity(TArray<FShooterInventoryItem> NewItems);

	UFUNCTION()
		void ClearProximity();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void InitializeInventory(float NewInventoryMaxWeight);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		FShooterInventoryItem GetInventoryItem(FName& DesiredItemID);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool SetInventoryItem(FShooterInventoryItem InventoryItem);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool SetInventoryItemAt(FShooterInventoryItem InventoryItem, int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool ClearInventoryItem(FName& DesiredItemID);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void ModifyInventoryMaxSize(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool IsSpaceFor(float Weight);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		FORCEINLINE TArray<FShooterInventoryItem> GetInventory()
	{
		return Inventory;
	}

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		FORCEINLINE TArray<FShooterInventoryItem> GetProximity()
	{
		return Proximity;
	}

	//UFUNCTION(BlueprintCallable, Category = "Inventory")
	//	FORCEINLINE FShooterInventoryItem* GetItemAt(int32 Index)
	//{
	//	return &(Inventory[Index]);
	//}

	//UFUNCTION(BlueprintCallable, Category = "Inventory")
	//	FORCEINLINE void RemoveItemAt(int32 Index)
	//{
	//	Inventory.RemoveAt(Index);
	//}






};
