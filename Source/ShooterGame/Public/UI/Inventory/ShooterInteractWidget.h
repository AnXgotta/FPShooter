// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Inventory/ShooterWidgetBase.h"
#include "ShooterInteractWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterInteractWidget : public UShooterWidgetBase
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* InteractText;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* InteractKey;

public:

	UFUNCTION()
		void SetInteractionText(FText InteractionText);

	UFUNCTION()
		void SetInteractionKeyText(FText InteractionKeyText);

};
