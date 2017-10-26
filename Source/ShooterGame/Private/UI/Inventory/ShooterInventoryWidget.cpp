// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWidgetBase.h"
#include "ShooterInventoryWidget.h"



void UShooterInventoryWidget::ClearInventoryList() {
	if (InventoryList) {
		InventoryList->ClearChildren();
	}
}

void UShooterInventoryWidget::AddToInventoryList(UShooterWidgetBase* NewWidget) {
	if (InventoryList) {
		InventoryList->AddChildToVerticalBox(NewWidget);
	}
}

void UShooterInventoryWidget::ClearProximityList() {
	if (ProximityList) {
		ProximityList->ClearChildren();
	}
}

void UShooterInventoryWidget::AddToProximityList(UShooterWidgetBase* NewWidget) {
	if (ProximityList) {
		ProximityList->AddChildToVerticalBox(NewWidget);
	}
}
