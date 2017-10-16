// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VerticalBox.h"
#include "SizeBox.h"
#include "UI/Inventory/ShooterWidgetBase.h"
#include "ShooterInventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterInventoryWidget : public UShooterWidgetBase
{
	GENERATED_BODY()

public:
	
		UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		UVerticalBox* ProximityCPPRef;

		UPROPERTY(BlueprintReadWrite, Category = "Inventory")
			UVerticalBox* InventoryCPPRef;

		UPROPERTY(BlueprintReadWrite, Category = "Inventory")
			USizeBox* PrimaryCPPRef;

		UPROPERTY(BlueprintReadWrite, Category = "Inventory")
			USizeBox* SecondaryCPPRef;

		UPROPERTY(BlueprintReadWrite, Category = "Inventory")
			USizeBox* Item1CPPRef;

		UPROPERTY(BlueprintReadWrite, Category = "Inventory")
			USizeBox* Item2CPPRef;
	
	
};
