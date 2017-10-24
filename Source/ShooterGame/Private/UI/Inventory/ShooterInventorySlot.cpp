// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "Image.h"
#include "Border.h"
#include "TextBlock.h"
#include "ShooterInventorySlot.h"




void UShooterInventorySlot::SetAmountText(FText AmountText) {
	if (Amount) {
		Amount->SetText(AmountText);
	}
}

void UShooterInventorySlot::SetNameText(FText NameText) {
	if (Name) {
		Name->SetText(NameText);
	}
}

void UShooterInventorySlot::SetIcon(UTexture2D* IconTexture) {
	if (Icon) {
		Icon->SetBrushFromTexture(IconTexture);
	}
}

void UShooterInventorySlot::SetBorderColor(FLinearColor NewColor) {
	if (ImageBorder) {
		ImageBorder->SetBrushColor(NewColor);
	}
}