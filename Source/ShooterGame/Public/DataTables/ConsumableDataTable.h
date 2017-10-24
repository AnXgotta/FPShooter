#include "ConsumableDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FConsumableDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
		

	UPROPERTY(EditDefaultsOnly, Category = "SpawnClass")
		TSubclassOf<class AShooterWorldActor_Consumable> WorldSpawnClass;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		FText ItemNameId;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		TEnumAsByte<EShooterConsumableType::Type> ConsumableType;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		float EffectValue;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		float EffectDuration;		

	UPROPERTY(EditAnywhere, Category = "Defaults")
		float TimeToUse;
	
	UPROPERTY(EditAnywhere, Category = "Defaults")
		bool bIsStackable;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 MaxStackable;

	

	FConsumableDataTable() {}

};