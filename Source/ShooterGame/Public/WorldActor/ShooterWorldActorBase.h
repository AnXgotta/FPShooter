// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterWorldActorBase.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterWorldActorBase : public AActor
{

	GENERATED_BODY()	

protected:

	int32 CustomOutlineDepthValue;


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
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Config)
	TEnumAsByte<EShooterInteractableType::Type> InteractableType;

	

	virtual void OnFocusBegin();
	virtual void OnFocusEnd();
	virtual FString GetInteractionText();
	
};
