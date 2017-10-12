// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterInventoryManagerComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERGAME_API UShooterInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

	



public:	
	// Sets default values for this component's properties
	UShooterInventoryManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		bool bIsInventoryOpen;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		bool bIsEquipmentOpen;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
		bool bIsContainerOpen;

	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		float InventorySize;

		
	
};
