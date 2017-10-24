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


	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ProximityList;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* InventoryList;

	UPROPERTY(meta = (BindWidget))
	class USizeBox* PrimaryBox;

	UPROPERTY(meta = (BindWidget))
	class USizeBox* SecondaryBox;

	UPROPERTY(meta = (BindWidget))
	class USizeBox* Item1Box;

	UPROPERTY(meta = (BindWidget))
	class USizeBox* Item2Box;

public:

	void ClearInventoryList();

	void AddToInventoryList(class UShooterWidgetBase* NewItem);


};
