#include "ConsumableDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FConsumableDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	
	UPROPERTY(EditAnywhere, Category = Config)
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, Category = Config)
		TEnumAsByte<EShooterConsumableType::Type> ConsumableType;

	UPROPERTY(EditAnywhere, Category = Config)
		float EffectValue;

	UPROPERTY(EditAnywhere, Category = Config)
		float EffectDuration;		

	FConsumableDataTable() {}

};