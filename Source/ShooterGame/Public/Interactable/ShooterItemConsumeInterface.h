#pragma once

#include "ShooterItemConsumeInterface.generated.h"

UINTERFACE(BlueprintType)
class UShooterItemConsumeInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IShooterItemConsumeInterface
{

	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IConsume")
		bool OnConsumeItem();

};
