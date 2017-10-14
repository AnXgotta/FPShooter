// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterWorldActorBase.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterWorldActorBase : public AActor, public IShooterInteractableActorInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShooterWorldActorBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(ReplicatedUsing = OnRep_WasInteracted)
		bool bWasInteracted;

	UFUNCTION()
		virtual void OnWasInteracted();

	/** [client] interaction happened */
	UFUNCTION()
		void OnRep_WasInteracted();

public:	

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Config)
		TEnumAsByte<EShooterItemType::Type> ItemType;
	 
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

		//Move interactable interface here to be overriden by children.
		// this prevents an extra cast to specifi objects for showing highlight/outline/usetext

	
};
