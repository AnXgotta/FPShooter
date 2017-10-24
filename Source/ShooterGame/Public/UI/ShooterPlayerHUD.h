// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterPlayerHUD : public AHUD
{
	GENERATED_BODY()

	class UShooterCrosshairWidget* CrosshairWidget;
	class UShooterInteractWidget* InteractionWidget;
	class UShooterInventoryWidget* InventoryWidget;


public:		

	AShooterPlayerHUD();

	UFUNCTION()
	void ShowInteractionWidget(FText InteractionKeyText, FText InteractionText);

	UFUNCTION()
	void HideInteractionWidget();

	UFUNCTION()
		void ShowInventory(bool bShow);

};
