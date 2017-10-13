#include "WeaponUIDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FWeaponUIDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	
	UPROPERTY(EditAnywhere, Category = WeaponUI)
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, Category = WeaponUI)
		FText Title;

	UPROPERTY(EditAnywhere, Category = WeaponUI)
		FText Description;

	UPROPERTY(EditAnywhere, Category = WeaponUI)
		FText Action;

	FWeaponUIDataTable() {}

};