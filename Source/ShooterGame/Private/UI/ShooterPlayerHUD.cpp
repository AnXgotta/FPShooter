// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWidgetBase.h"
#include "ShooterCrosshairWidget.h"
#include "ShooterInteractWidget.h"
#include "ShooterInventoryWidget.h"
#include "ShooterInventorySlot.h"
#include "ShooterPlayerHUD.h"


AShooterPlayerHUD::AShooterPlayerHUD() {

	ConstructorHelpers::FClassFinder<UShooterCrosshairWidget> CrosshairWidgetClass(TEXT("/Game/UI/HUD/BPW_CrosshairWidget"));

	ConstructorHelpers::FClassFinder<UShooterInteractWidget> InteractionWidgetClass(TEXT("/Game/UI/Inventory/InteractText"));

	ConstructorHelpers::FClassFinder<UShooterInventoryWidget> InventoryWidgetClass(TEXT("/Game/UI/Inventory/Inventory"));

	ConstructorHelpers::FClassFinder<UShooterInventorySlot> InventorySlotWidgetClassRef(TEXT("/Game/UI/Inventory/Inventory_Slot"));

	InventorySlotWidgetClass = InventorySlotWidgetClassRef.Class;


	UWorld* World = GetWorld();
	if (World) {

		if (InteractionWidgetClass.Class) {
			InteractionWidget = CreateWidget<UShooterInteractWidget>(World, InteractionWidgetClass.Class);
			if (InteractionWidget) {
				InteractionWidget->AddToViewport();
				InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}

		if (CrosshairWidgetClass.Class) {
			CrosshairWidget = CreateWidget<UShooterCrosshairWidget>(World, CrosshairWidgetClass.Class);
			if (CrosshairWidget) {
				CrosshairWidget->AddToViewport();
				CrosshairWidget->SetVisibility(ESlateVisibility::Visible);
			}
		}

		if (InventoryWidgetClass.Class) {
			InventoryWidget = CreateWidget<UShooterInventoryWidget>(World, InventoryWidgetClass.Class);
			if (InventoryWidget) {
				InventoryWidget->AddToViewport();
				InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}

	}

}


void AShooterPlayerHUD::ShowInteractionWidget(FText InteractionKeyText, FText InteractionText)
{

	if (InteractionText.IsEmpty()) return;

	if (InteractionWidget)
	{
		InteractionWidget->SetInteractionText(InteractionText);
		InteractionWidget->SetInteractionKeyText(InteractionKeyText);
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AShooterPlayerHUD::HideInteractionWidget()
{
	if (InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AShooterPlayerHUD::ShowProximity(TArray<FShooterInventoryItem> ProximityReference)
{
	if (InventoryWidget)
	{
		InventoryWidget->ClearProximityList();
		if (ProximityReference.Num() <= 0) return;
		UWorld* World = GetWorld();
		if (World) {
			for (int i = 0; i < ProximityReference.Num(); i++) {
				UShooterInventorySlot* NewWidget = CreateWidget<UShooterInventorySlot>(World, InventorySlotWidgetClass);

				if (!NewWidget) return;

				NewWidget->SetIcon(ProximityReference[i].Icon);
				NewWidget->SetNameText(FText::FromName(ProximityReference[i].Name));
				NewWidget->SetAmountText(FText::FromString(FString::FromInt(ProximityReference[i].Amount)));

				switch (ProximityReference[i].InteractableType) {
				case EShooterInteractableType::Consumable:
				{
					NewWidget->SetBorderColor(FLinearColor::Blue);
				}
				break;
				case EShooterInteractableType::Ammo:
				{
					NewWidget->SetBorderColor(FLinearColor::Green);
				}
				case EShooterInteractableType::WeaponAttachment:
				{
					NewWidget->SetBorderColor(FLinearColor::Yellow);
				}
				break;
				}
				NewWidget->SetVisibility(ESlateVisibility::Visible);
				InventoryWidget->AddToProximityList(NewWidget);
			}
		}
	}
}

void AShooterPlayerHUD::ShowInventory(TArray<FShooterInventoryItem> InventoryReference)
{
	if (InventoryWidget)
	{
		InventoryWidget->ClearInventoryList();
		UWorld* World = GetWorld();
		if (World) {
			for (int i = 0; i < InventoryReference.Num(); i++) {
				UShooterInventorySlot* NewWidget = CreateWidget<UShooterInventorySlot>(World, InventorySlotWidgetClass);
				NewWidget->SetIcon(InventoryReference[i].Icon);
				NewWidget->SetNameText(FText::FromName(InventoryReference[i].Name));
				NewWidget->SetAmountText(FText::FromString(FString::FromInt(InventoryReference[i].Amount)));

				switch (InventoryReference[i].InteractableType) {
				case EShooterInteractableType::Consumable:
				{
					NewWidget->SetBorderColor(FLinearColor::Blue);
				}
				break;
				case EShooterInteractableType::Ammo:
				{
					NewWidget->SetBorderColor(FLinearColor::Green);
				}
				case EShooterInteractableType::WeaponAttachment:
				{
					NewWidget->SetBorderColor(FLinearColor::Yellow);
				}
				break;
				}
				NewWidget->SetVisibility(ESlateVisibility::Visible);
				InventoryWidget->AddToInventoryList(NewWidget);
			}

			InventoryWidget->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void AShooterPlayerHUD::UpdateInventoryNoShow(TArray<FShooterInventoryItem> InventoryReference)
{
	if (InventoryWidget)
	{
		InventoryWidget->ClearInventoryList();
		UWorld* World = GetWorld();
		if (World) {
			for (int i = 0; i < InventoryReference.Num(); i++) {
				UShooterInventorySlot* NewWidget = CreateWidget<UShooterInventorySlot>(World, InventorySlotWidgetClass);
				NewWidget->SetIcon(InventoryReference[i].Icon);
				NewWidget->SetNameText(FText::FromName(InventoryReference[i].Name));
				NewWidget->SetAmountText(FText::FromString(FString::FromInt(InventoryReference[i].Amount)));

				switch (InventoryReference[i].InteractableType) {
				case EShooterInteractableType::Consumable:
				{
					NewWidget->SetBorderColor(FLinearColor::Blue);
				}
				break;
				case EShooterInteractableType::Ammo:
				{
					NewWidget->SetBorderColor(FLinearColor::Green);
				}
				case EShooterInteractableType::WeaponAttachment:
				{
					NewWidget->SetBorderColor(FLinearColor::Yellow);
				}
				break;
				}
				NewWidget->SetVisibility(ESlateVisibility::Visible);
				InventoryWidget->AddToInventoryList(NewWidget);
			}
		}
	}
}

void AShooterPlayerHUD::HideInventory() {
	if (InventoryWidget)
	{
		InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

UShooterInventoryWidget* AShooterPlayerHUD::GetInventoryWidget() {
	return InventoryWidget;
}