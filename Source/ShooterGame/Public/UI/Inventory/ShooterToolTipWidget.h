// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterTypes.h"
#include "UI/Inventory/ShooterWidgetBase.h"
#include "ShooterToolTipWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterToolTipWidget : public UShooterWidgetBase
{
	GENERATED_BODY()
	
public:

		UPROPERTY(BlueprintReadWrite, Category = "Config")
		FInventoryItemToolTip ToolTipInfo;
	
	
};
