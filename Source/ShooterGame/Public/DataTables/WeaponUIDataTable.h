#include "WeaponUIDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FWeaponUIDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = "Consumable UI")
		FText ItemId;

	UPROPERTY(EditAnywhere, Category = WeaponUI)
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, Category = WeaponUI)
		FText Title;

	UPROPERTY(EditAnywhere, Category = WeaponUI)
		FText Description;

	FWeaponUIDataTable() {}

};