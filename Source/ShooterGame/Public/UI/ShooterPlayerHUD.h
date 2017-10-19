// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterInventoryWidget.h"
#include "ShooterPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterPlayerHUD : public AHUD
{
	GENERATED_BODY()
			
public:

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		UShooterInventoryWidget* InventoryWidgetCPPRef;

	FORCEINLINE UShooterInventoryWidget* GetInventoryWidget() { return InventoryWidgetCPPRef; }

};
