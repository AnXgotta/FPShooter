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

public:
		UPROPERTY(BlueprintReadWrite, Category = "Config")
		FInventorySlotInformation SlotInformation;

		UPROPERTY(BlueprintReadWrite, Category = "Config")
		bool bIsSlotHovered;

	UPROPERTY(BlueprintReadWrite, Category = "Config")
		bool bIsRightMouseButtonDown;

	
	
};
