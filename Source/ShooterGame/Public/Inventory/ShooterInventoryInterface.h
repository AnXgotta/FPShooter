#pragma once

#include "CoreMinimal.h"
#include "ShooterInventoryInterface.generated.h"

UINTERFACE(MinimalAPI)
class UShooterInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

class SHOOTERGAME_API IShooterInventoryInterface
{

	GENERATED_BODY()

public:

		virtual FShooterInventoryContainer GetContainerProperties() = 0;
		virtual UShooterInventoryComponent* GetContainerInventory() = 0;
		virtual TArray<APlayerState*> GetPlayersViewing() = 0;
		virtual bool CanStoreItems() = 0;

};
