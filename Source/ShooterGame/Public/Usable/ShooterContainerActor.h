// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterInventoryComponent.h"
#include "ShooterInventoryInterface.h"
#include "Usable/ShooterUsableActor.h"
#include "ShooterContainerActor.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterContainerActor : public AShooterUsableActor, public IShooterInventoryInterface
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InitializeInventory();

	TArray<APlayerState*> PlayersViewing;


public:

	AShooterContainerActor();

	UPROPERTY()
		UShooterInventoryComponent* InventoryComponent;

		UPROPERTY(EditDefaultsOnly, Category = "Defaults")
		FShooterInventoryContainer ContainerInfo;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
			FShooterInventoryContainer GetContainerProperties();
		virtual FShooterInventoryContainer GetContainerProperties_Implementation() override;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
			UShooterInventoryComponent* GetContainerInventory();
		virtual UShooterInventoryComponent* GetContainerInventory_Implementation() override;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
			TArray<APlayerState*> GetPlayersViewing();
		virtual TArray<APlayerState*> GetPlayersViewing_Implementation() override;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
			bool CanStoreItems();
		virtual bool CanStoreItems_Implementation() override;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInventory")
			bool ContainerLooted();
		virtual bool ContainerLooted_Implementation() override;

		virtual bool OnActorUsed_Implementation(APlayerController* PlayerController) override;
	
};
