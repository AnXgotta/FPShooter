#pragma once

#include "ShooterPlayerController.h"
#include "ShooterItemPUPDInterface.generated.h"

UINTERFACE(BlueprintType)
class UShooterItemPUPDInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IShooterItemPUPDInterface
{

	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IPUPD")
		bool OnPickUp(AShooterPlayerController* PlayerController);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IPUPD")
		bool OnPutDown(AShooterPlayerController* PlayerController);

};
