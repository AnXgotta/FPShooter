// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Inventory/ShooterWidgetBase.h"
#include "ShooterTypes.h"
#include "ShooterInventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterInventorySlot : public UShooterWidgetBase
{
	GENERATED_BODY()


	UPROPERTY(meta = (BindWidget))
		class UImage* Icon;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Amount;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
		class UBorder* ImageBorder;

public:

	UFUNCTION()
		void SetAmountText(FText AmountText);

	UFUNCTION()
		void SetNameText(FText NameText);

	UFUNCTION()
		void SetIcon(UTexture2D* IconTexture);

	UFUNCTION()
		void SetBorderColor(FLinearColor NewColor);

		UPROPERTY(BlueprintReadWrite, Category = "Config")
		bool bIsSlotHovered;

	UPROPERTY(BlueprintReadWrite, Category = "Config")
		bool bIsRightMouseButtonDown;

	
	
};
