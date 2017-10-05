// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShake.h"
#include "ShooterWeaponCameraShake.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterWeaponCameraShake : public UCameraShake
{
	GENERATED_BODY()
	
public:

	void Initialize(const float VerticalCameraBounceAmplitude, const float CameraShakeAmplitude, const float CameraShakeFrequency);
	
	
};
