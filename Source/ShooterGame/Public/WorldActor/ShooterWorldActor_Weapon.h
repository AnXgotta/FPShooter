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
class SHOOTERGAME_API AShooterWorldActor_Weapon : public AShooterWorldActorBase, public IShooterInteractableActorInterface, public IShooterItemPUPDInterface
{
	GENERATED_BODY()
	
	/** weapon data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	FText WeaponNameId;

	/** attachment data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	TArray<FText> AttachmentNameIds;

public:

	AShooterWorldActor_Weapon();

	FORCEINLINE FText GetWeaponNameId() { return WeaponNameId; }
	FORCEINLINE TArray<FText> GetAttachmentNameIds() { return AttachmentNameIds; }
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnPickUp(AShooterPlayerController* PlayerController);
	virtual bool OnPickUp_Implementation(AShooterPlayerController* PlayerController) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IPUPD")
		bool OnPutDown(AShooterPlayerController* PlayerController);
	virtual bool OnPutDown_Implementation(AShooterPlayerController* PlayerController) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool OnActorInteracted(APlayerController* PlayerController);
	virtual bool OnActorInteracted_Implementation(APlayerController* PlayerController) override;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool BeginOutlineFocus();
	virtual bool BeginOutlineFocus_Implementation() override;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool EndOutlineFocus();
	virtual bool EndOutlineFocus_Implementation() override;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool GetIsActorInteractable();
	virtual bool GetIsActorInteractable_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		FString GetInteractActionText();
	virtual FString GetInteractActionText_Implementation() override;
};
