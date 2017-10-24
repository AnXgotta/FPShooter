// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"

#include "ShooterPlayerHUD.h"
#include "ShooterInventoryComponent.h"
#include "ShooterGame_BR.h"

#include "ShooterInventoryManagerComponent.h"


// Sets default values for this component's properties
UShooterInventoryManagerComponent::UShooterInventoryManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bReplicates = true;
	//PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UShooterInventoryManagerComponent::BeginPlay()
{
	Super::BeginPlay();


}


//// Called every frame
//void UShooterInventoryManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}
//
bool UShooterInventoryManagerComponent::InitializeInventory(UShooterInventoryComponent* NewInventoryComponent, float MaxWeight) {

	InventoryComponent = NewInventoryComponent;
	if (InventoryComponent) {
		InventoryComponent->InventoryMaxWeight = MaxWeight;
	}
	else {
		return false;
	}

	return true;
}

void UShooterInventoryManagerComponent::ToggleInventory() {
	if (bIsInventoryOpen) {
		CloseInventory();
	}
	else {
		OpenInventory();
	}
	bIsInventoryOpen = !bIsInventoryOpen;
}

void UShooterInventoryManagerComponent::OpenInventory() {
	AShooterPlayerHUD* PlayerHUD = nullptr;
	if (GetOwner()) {
		AShooterCharacter* Pawn = Cast<AShooterCharacter>(GetOwner());
		if (Pawn) {
			AShooterPlayerController* PC = Cast<AShooterPlayerController>(Pawn->GetController());
			if (PC) {
				PlayerHUD = Cast<AShooterPlayerHUD>(PC->GetHUD());
			}

		}
	}

	if (PlayerHUD) {
		PlayerHUD->ShowInventory(InventoryComponent->GetInventory());
	}
}

void UShooterInventoryManagerComponent::CloseInventory() {
	AShooterPlayerHUD* PlayerHUD = nullptr;
	if (GetOwner()) {
		AShooterCharacter* Pawn = Cast<AShooterCharacter>(GetOwner());
		if (Pawn) {
			AShooterPlayerController* PC = Cast<AShooterPlayerController>(Pawn->GetController());
			if (PC) {
				PlayerHUD = Cast<AShooterPlayerHUD>(PC->GetHUD());
			}
		}
	}

	if (PlayerHUD) {
		PlayerHUD->HideInventory();
	}
}

int UShooterInventoryManagerComponent::AddItemToInventory(FName NewItemId, int32 Amount) {
	FShooterInventoryItem NewItem;
	UWorld* World = GetWorld();
	if (World) {
		AShooterGame_BR* Game = Cast<AShooterGame_BR>(World->GetAuthGameMode());
		if (Game) {
			NewItem = Game->Data_GetItemInventoryItem(NewItemId.ToString());
		}
	}
	NewItem.Amount = Amount;

	int32 RemainingItems = AddItemToInventoryImp(NewItem);

	return RemainingItems;
}

int UShooterInventoryManagerComponent::AddItemToInventoryImp(FShooterInventoryItem NewItem) {
	int32 RemainingAmountThatCanFit = NewItem.Amount;
	int32 AmountNotAdded = 0;

	if (!InventoryComponent) {
		return NewItem.Amount;
	}

	// can all fit? how about some?
	if (InventoryComponent->IsSpaceFor(NewItem.GetTotalWeight())) {
		RemainingAmountThatCanFit = NewItem.Amount;
		
	}
	else {
		for (int i = NewItem.Amount; i >= 0; i--) {
			if (InventoryComponent->IsSpaceFor(NewItem.Weight * i)) {
				RemainingAmountThatCanFit = i + 1;
				break;
			}
		}
	}

	// inventory can't fit any of this item
	if (RemainingAmountThatCanFit <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("Item Added 2"));
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

	for (int i = 0; i < InventoryComponent->GetInventory().Num(); i++) {
		if (RemainingAmount <= 0) {
			break;
		}
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
			InventoryComponent->SetInventoryItemAt(LItem, ItemIndex);
			RemainingAmount = 0;
		}
		else {
			LItem.Amount = LItem.MaxStackable;
			InventoryComponent->SetInventoryItemAt(LItem, ItemIndex);
			RemainingAmount -= FreeSpaceAmount;
		}
	}

	return RemainingAmount;
}

void UShooterInventoryManagerComponent::AddItem(FShooterInventoryItem NewItem) {
	UE_LOG(LogTemp, Warning, TEXT("Item Added!!!"));
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
	}
	else {
		RemainingAmount = 0;
		InventoryComponent->GetInventory()[ItemIndex].Amount -= Amount;
	}
	return RemainingAmount;
}
