// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterUsableActorInterface.h"
#include "ShooterUsableActor.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterUsableActor : public AActor, public IShooterUsableActorInterface
{
	GENERATED_BODY()

	UPROPERTY(Replicated)
	bool bIsUsable;

	UPROPERTY(ReplicatedUsing = OnRep_WasUsed)
	bool bWasUsed;

	UFUNCTION()
		void OnRep_WasUsed();

	UFUNCTION()
		bool OnWasUsed();


public:	

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		FName Name;

	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		FText Action;

	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		USoundCue* UsedSound;

	// Sets default values for this actor's properties
	AShooterUsableActor();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IUsable")
		bool GetIsActorUsable();
	virtual bool GetIsActorUsable_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IUsable")
		bool OnActorUsed(APlayerController* PlayerController);
	virtual bool OnActorUsed_Implementation(APlayerController* PlayerController) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IUsable")
		FString GetUseActionText();
	virtual FString GetUseActionText_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IUsable")
		bool BeginOutlineFocus();
	virtual bool BeginOutlineFocus_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IUsable")
		bool EndOutlineFocus();
	virtual bool EndOutlineFocus_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
