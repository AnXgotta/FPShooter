// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShooterWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:

		UPROPERTY(BlueprintReadOnly)
		class AShooterPlayerController* OwningController;
	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
};
