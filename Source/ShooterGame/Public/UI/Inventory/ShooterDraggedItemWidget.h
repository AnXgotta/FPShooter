// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterTypes.h"
#include "UI/Inventory/ShooterWidgetBase.h"
#include "ShooterDraggedItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterDraggedItemWidget : public UShooterWidgetBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Config")
		FInventorySlotInformation ItemInformation;

	UPROPERTY(BlueprintReadWrite, Category = "Config")
		float Amount;

};
