// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterInventoryComponent.h"


// Sets default values for this component's properties
UShooterInventoryComponent::UShooterInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	InventoryWeight = 0.0f;
}


void UShooterInventoryComponent::InitializeInventory(float NewInventoryMaxWeight) {
	InventoryMaxWeight = NewInventoryMaxWeight;
	InventoryWeight = 0;
	Inventory.Empty();	
}

FShooterInventoryItem UShooterInventoryComponent::GetInventoryItem(FName& DesiredItemID) {

	if (Inventory.Num() < 0) {
		return FShooterInventoryItem();
	} 


	for (int i = 0; i < Inventory.Num(); i++) {
		if (Inventory[i].ID.IsEqual(DesiredItemID)) {
			return Inventory[i];
		}
	}

	return FShooterInventoryItem();
}

bool UShooterInventoryComponent::SetInventoryItem(FShooterInventoryItem InventoryItem) {
	return Inventory.Add(InventoryItem) > -1;
}

bool UShooterInventoryComponent::ClearInventoryItem(FName& DesiredItemID) {

	int DesiredItemIndex = -1;

	for (int i = 0; i < Inventory.Num(); i++) {
		if (Inventory[i].ID.IsEqual(DesiredItemID)) {
			DesiredItemIndex = i;
			break;
		}
	}

	if (DesiredItemIndex < 0) {
		return false;
	}

	Inventory.RemoveAt(DesiredItemIndex);

	return true;
}

void UShooterInventoryComponent::ModifyInventoryMaxSize(float Amount) {
	InventoryMaxWeight += Amount;
}

TArray<FShooterInventoryItem> UShooterInventoryComponent::GetInventory() { 
	return Inventory;
}