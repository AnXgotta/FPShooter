// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "TextBlock.h"
#include "ShooterInteractWidget.h"


void UShooterInteractWidget::SetInteractionText(FText InteractionText) {
	if (InteractText) {
		InteractText->SetText(InteractionText);
	}
}

void UShooterInteractWidget::SetInteractionKeyText(FText InteractionKeyText) {
	if (InteractKey) {
		InteractKey->SetText(InteractionKeyText);
	}
}

