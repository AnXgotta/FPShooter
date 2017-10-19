// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterPlayerHUD.h"
#include "ShooterInventoryManagerComponent.h"


// Sets default values for this component's properties
UShooterInventoryManagerComponent::UShooterInventoryManagerComponent()
{

	InventoryHelper = NewObject<UShooterInventoryHelper>(UShooterInventoryHelper::StaticClass());
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bReplicates = true;
	//PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UShooterInventoryManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	
	// ...
	
}


//// Called every frame
//void UShooterInventoryManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

bool UShooterInventoryManagerComponent::InitializeInventory(AShooterCharacter* NewPawn, float MaxWeight) {
	Pawn = NewPawn;
	InventoryComponent = Pawn->GetInventoryComponent();
	InventoryComponent->InventoryMaxWeight = MaxWeight;
	AShooterPlayerController* PC = Cast<AShooterPlayerController>(Pawn->GetController());
	if (PC) {
		AShooterPlayerHUD* PlayerHUD = Cast<AShooterPlayerHUD>(PC->GetHUD());
		if (PlayerHUD) {
			InventoryWidget = PlayerHUD->GetInventoryWidget();
		}
	}
	return Pawn && InventoryWidget;
}

void UShooterInventoryManagerComponent::OpenInventory() {
	UE_LOG(LogTemp, Warning, TEXT("InvenManager Open Inventory"));
	if (InventoryWidget) {
		UE_LOG(LogTemp, Warning, TEXT("InvenManager Open Inven - Inventory not null"));
		InventoryWidget->SetVisibility(ESlateVisibility::Visible);
		bIsInventoryOpen = true;
	}
}

void UShooterInventoryManagerComponent::CloseInventory() {
	UE_LOG(LogTemp, Warning, TEXT("InvenManager Close Inventory"));
	if (InventoryWidget) {
		UE_LOG(LogTemp, Warning, TEXT("InvenManager Open Inven - Inventory not null"));
		InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
		bIsInventoryOpen = false;
	}
}

int UShooterInventoryManagerComponent::AddItemToInventory(FName NewItemId) {


	return 0;
}

int UShooterInventoryManagerComponent::AddItemToInventoryImp(FShooterInventoryItem NewItem) {
	int32 RemainingAmountThatCanFit = NewItem.Amount;
	int32 AmountNotAdded = 0;

	// can all fit? how about some?
	if (InventoryComponent->IsSpaceFor(NewItem.GetTotalWeight())) {
		RemainingAmountThatCanFit = NewItem.Amount;
	}
	else {
		for (int i = NewItem.Amount; i >= 0; i--) {
			if (InventoryComponent->IsSpaceFor(NewItem.Weight * i)) {
				RemainingAmountThatCanFit = i;
				break;
			}
		}
	}

	// inventory can't fit any of this item
	if (RemainingAmountThatCanFit <= 0) {
		return NewItem.Amount;
	}

	AmountNotAdded = NewItem.Amount - RemainingAmountThatCanFit;

	// can we stack the amount that can fit?
	if (NewItem.bIsStackable) {
		RemainingAmountThatCanFit = FindItemAndAddToStack(NewItem.ID, RemainingAmountThatCanFit);
	}

	// did all fit in a stack?
	if (RemainingAmountThatCanFit <= 0) {
		return 0;
	}

	AmountNotAdded -= RemainingAmountThatCanFit;

	// put remaining amount in new item
	NewItem.Amount = RemainingAmountThatCanFit;
	AddItem(NewItem);

	return AmountNotAdded;
}

int UShooterInventoryManagerComponent::FindItemAndAddToStack(FName ItemId, int ItemAmount) {
	int32 RemainingAmount = ItemAmount;

	for (int i = 0; i < InventoryComponent->GetInventory().Num() || RemainingAmount == 0; i++) {
		if (InventoryComponent->GetInventory()[i].ID == ItemId) {
			RemainingAmount = AddItemToStack(i, RemainingAmount);
		}
	}

	return RemainingAmount;
}

int UShooterInventoryManagerComponent::AddItemToStack(int32 ItemIndex, int ItemAmountToAdd) {

	int32 RemainingAmount = ItemAmountToAdd;

	FShooterInventoryItem LItem = InventoryComponent->GetInventory()[ItemIndex];
	// is there free space
	if (LItem.Amount < LItem.MaxStackable) {
		// is there space for all
		int32 FreeSpaceAmount = LItem.MaxStackable - LItem.Amount;
		if (RemainingAmount <= FreeSpaceAmount) {
			LItem.Amount += RemainingAmount;
			RemainingAmount = 0;
		}
		else {
			LItem.Amount = LItem.MaxStackable;
			RemainingAmount -= FreeSpaceAmount;
		}
	}

	return RemainingAmount;
}

void UShooterInventoryManagerComponent::AddItem(FShooterInventoryItem NewItem) {
	InventoryComponent->SetInventoryItem(NewItem);
}

bool UShooterInventoryManagerComponent::RemoveItemFromInventory(FName ItemId, int Amount) {
	int RemainingAmount = Amount;
	if (CheckForDesiredItemAmount(ItemId, Amount)) {
		for (int i = 0; InventoryComponent->GetInventory().Num(); i++) {
			if (InventoryComponent->GetInventory()[i].ID == ItemId) {
				RemainingAmount = RemoveItem(i, RemainingAmount);
				if (RemainingAmount <= 0) {
					return true;
				}
			}
		}
	}

	return false;
}

bool UShooterInventoryManagerComponent::CheckForDesiredItemAmount(FName ItemId, int DesiredAmount) {
	int AmountInInventory = 0;
	for (int i = 0; InventoryComponent->GetInventory().Num(); i++) {
		if (InventoryComponent->GetInventory()[i].ID == ItemId) {
			AmountInInventory += InventoryComponent->GetInventory()[i].Amount;
			if (AmountInInventory >= DesiredAmount) {
				return true;
			}
		}
	}
	return false;
}

int UShooterInventoryManagerComponent::RemoveItem(int ItemIndex, int Amount) {
	int RemainingAmount = Amount;
	if (Amount >= InventoryComponent->GetInventory()[ItemIndex].Amount) {
		RemainingAmount = Amount - InventoryComponent->GetInventory()[ItemIndex].Amount;
		InventoryComponent->GetInventory().RemoveAt(ItemIndex);
	} else {
		RemainingAmount = 0;
		InventoryComponent->GetInventory()[ItemIndex].Amount -= Amount;
	}
	return RemainingAmount;
}



// ACCESOR / MUTATOR

FWeaponData UShooterInventoryManagerComponent::GetWeaponConfigInfo(FString ItemNameId) {
	return InventoryHelper->GetWeaponInventoryInfo(ItemNameId);

}