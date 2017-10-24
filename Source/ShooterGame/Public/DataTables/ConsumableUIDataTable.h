#include "ConsumableUIDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FConsumableUIDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Consumable UI")
		FText ItemId;

	UPROPERTY(EditAnywhere, Category = "Consumable UI")
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, Category = "Consumable UI")
		FText Title;

	UPROPERTY(EditAnywhere, Category = "Consumable UI")
		FText Description;

	UPROPERTY(EditAnywhere, Category = "Consumable UI")
		float Weight;

	FConsumableUIDataTable() {}

};