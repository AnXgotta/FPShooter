// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterInventoryWidget.h"
#include "ShooterTypes.h"
#include "ShooterInventoryManagerComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERGAME_API UShooterInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()


	AShooterCharacter* Pawn;
	UShooterInventoryWidget* InventoryWidget;

	UShooterInventoryComponent* InventoryComponent;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Sets default values for this component's properties
	UShooterInventoryManagerComponent();
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		bool bIsInventoryOpen;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		bool bIsEquipmentOpen;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		bool bIsContainerOpen;

	
	bool InitializeInventory(AShooterCharacter* NewPawn, float MaxWeight);
		
	// do these need to be Client-Reliable??
	void OpenInventory();
	void CloseInventory();

	int32 AddItemToInventory(FName NewItemId);
	int32 AddItemToInventoryImp(FShooterInventoryItem NewItem);
	bool RemoveItemFromInventory(FName ItemId, int32 Amount);

private:

	
	int32 FindItemAndAddToStack(FName ItemId, int32 ItemAmount);
	int32 AddItemToStack(int32 ItemIndex, int32 ItemAmountToAdd);
	void AddItem(FShooterInventoryItem NewItem);

	
	bool CheckForDesiredItemAmount(FName ItemId, int32 DesiredAmount);
	int RemoveItem(int ItemIndex, int Amount);

};
