#include "WeaponUIDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FWeaponUIDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = "Weapon UI")
		FText ItemId;

	UPROPERTY(EditAnywhere, Category = "Weapon UI")
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, Category = "Weapon UI")
		FText Title;

	UPROPERTY(EditAnywhere, Category = "Weapon UI")
		FText Description;

	UPROPERTY(EditAnywhere, Category = "Weapon UI")
		float Weight;
	
	UPROPERTY(EditAnywhere, Category = "Defaults")
		bool bIsStackable;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 MaxStackable;

	FWeaponUIDataTable() {}

};