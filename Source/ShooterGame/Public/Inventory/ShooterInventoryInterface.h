#pragma once

#include "ShooterInventoryInterface.generated.h"

UINTERFACE(BlueprintType)
class UShooterInventoryInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IShooterInventoryInterface
{

	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
		FShooterInventoryContainer GetContainerProperties();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
		AShooterInventoryComponent GetContainerInventory();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
		TArray<APlayerState> GetPlayersViewing();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
		bool CanStoreItems();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
		FString ContainerLooted();

};
