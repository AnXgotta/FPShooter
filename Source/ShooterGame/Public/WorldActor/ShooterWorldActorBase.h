// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterWorldActorBase.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterWorldActorBase : public AActor, public IShooterInteractableActorInterface
{
	GENERATED_BODY()


protected:


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** weapon data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
		FString ItemNameId;

	/** weapon data */
	UPROPERTY(EditDefaultsOnly, Category = Config)
		FString InteractionText;

	UPROPERTY(ReplicatedUsing = OnRep_WasInteracted)
		bool bWasInteracted;

	UFUNCTION()
		virtual void OnWasInteracted();

	/** [client] interaction happened */
	UFUNCTION()
		void OnRep_WasInteracted();

public:	


	// Sets default values for this actor's properties
	AShooterWorldActorBase();

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Config)
		TEnumAsByte<EShooterItemType::Type> ItemType;

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	int32 CustomOutlineDepthValue;
	 
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool OnActorInteracted(AShooterCharacter* Player);
	virtual bool OnActorInteracted_Implementation(AShooterCharacter* Player) override;

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
