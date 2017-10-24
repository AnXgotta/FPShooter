// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterCrosshairWidget.h"
#include "ShooterInteractWidget.h"
#include "ShooterInventoryWidget.h"
#include "ShooterPlayerHUD.h"


AShooterPlayerHUD::AShooterPlayerHUD() {

	ConstructorHelpers::FClassFinder<UShooterCrosshairWidget> CrosshairWidgetClass(TEXT("/Game/UI/HUD/BPW_CrosshairWidget"));

	ConstructorHelpers::FClassFinder<UShooterInteractWidget> InteractionWidgetClass(TEXT("/Game/UI/Inventory/InteractText"));

	ConstructorHelpers::FClassFinder<UShooterInventoryWidget> InventoryWidgetClass(TEXT("/Game/UI/Inventory/Inventory"));


	if (InteractionWidgetClass.Class) {
		UWorld* World = GetWorld();
		if (World) {
			InteractionWidget = CreateWidget<UShooterInteractWidget>(World, InteractionWidgetClass.Class);
			if (InteractionWidget) {
				InteractionWidget->AddToViewport();
				InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
			}

			CrosshairWidget = CreateWidget<UShooterCrosshairWidget>(World, CrosshairWidgetClass.Class);
			if (CrosshairWidget) {
				CrosshairWidget->AddToViewport();
				CrosshairWidget->SetVisibility(ESlateVisibility::Visible);
			}

			InventoryWidget = CreateWidget<UShooterInventoryWidget>(World, InventoryWidgetClass.Class);
			if (InventoryWidget) {
				InventoryWidget->AddToViewport();
				InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}


void AShooterPlayerHUD::ShowInteractionWidget(FText InteractionKeyText, FText InteractionText) {

	if (InteractionText.IsEmpty()) return;

	if (InteractionWidget) {
		InteractionWidget->SetInteractionText(InteractionText);
		InteractionWidget->SetInteractionKeyText(InteractionKeyText);
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AShooterPlayerHUD::HideInteractionWidget() {
	if (InteractionWidget) {
		InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AShooterPlayerHUD::ShowInventory(bool bShow) {
	if (InventoryWidget) {
		InventoryWidget->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}