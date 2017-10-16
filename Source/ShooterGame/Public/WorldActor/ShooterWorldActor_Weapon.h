// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterItemPUPDInterface.h"
#include "ShooterInteractableActorInterface.h"
#include "WorldActor/ShooterWorldActorBase.h"
#include "ShooterWorldActor_Weapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterWorldActor_Weapon : public AShooterWorldActorBase, public IShooterItemPUPDInterface
{
	GENERATED_BODY()
	
	/** weapon data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	FText WeaponId;

	/** attachment data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	TArray<FText> AttachmentNameIds;

protected:

	UFUNCTION()
		virtual void OnWasInteracted() override;

public:

	AShooterWorldActor_Weapon();

	FORCEINLINE FText GetWeaponNameId() { return WeaponNameId; }
	FORCEINLINE TArray<FText> GetAttachmentNameIds() { return AttachmentNameIds; }
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnPickUp(AShooterCharacter* Player);
	virtual bool OnPickUp_Implementation(AShooterCharacter* Player) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnPutDown();
	virtual bool OnPutDown_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool OnActorInteracted(AShooterCharacter* Player);
	virtual bool OnActorInteracted_Implementation(AShooterCharacter* Player) override;

};
