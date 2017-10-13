#pragma once

#include "ShooterItemUseInterface.generated.h"

UINTERFACE(BlueprintType)
class UShooterItemUseInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IShooterItemUseInterface
{

	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IUse")
		bool OnUseItem();

};
