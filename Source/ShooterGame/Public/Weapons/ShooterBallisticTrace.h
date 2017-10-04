// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterBallisticTrace.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterBallisticTrace : public AActor
{
	GENERATED_BODY()

	USceneComponent* TraceStart;
	USceneComponent* TraceEnd;

	FVector Origin;

	FTimerHandle BallisticTraceTimerHandle;
	
	// frequency with which to do the next trace segment (Milliseconds)
	float BallisticTraceFrequency;
	float BallisticTraceLifetime;

	float TraceStartTime;
	float AimAngle;
	
	void StartBallisticTrace();
	void PerformBallisticTrace();
	void HandleImpact(const FHitResult& Impact);
	
public:	

		

	// Sets default values for this actor's properties
	AShooterBallisticTrace();

	UPROPERTY(BlueprintReadWrite, Category = TraceStat)
		float MVelocity;
	UPROPERTY(BlueprintReadWrite, Category = TraceStat)
		float XVelocity;
	UPROPERTY(BlueprintReadWrite, Category = TraceStat)
		float ZVelocity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** find hit */
	FHitResult BallisticsTrace(const FVector& TraceFrom, const FVector& TraceTo) const;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InitializeValues(const float MuzzleVelocity);

	
	
};
