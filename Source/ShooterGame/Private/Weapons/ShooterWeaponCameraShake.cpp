// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWeaponCameraShake.h"




void UShooterWeaponCameraShake::Initialize(const float VerticalCameraBounceAmplitude, const float CameraShakeAmplitude, const float CameraShakeFrequency) {
	bSingleInstance = false;
	OscillationDuration = 0.25f;
	AnimBlendInTime = 0.1f;
	AnimBlendOutTime = 0.1f;
	RotOscillation.Pitch.Amplitude = VerticalCameraBounceAmplitude;
	RotOscillation.Pitch.Frequency = 1.0f;
	RotOscillation.Pitch.InitialOffset = EInitialOscillatorOffset::EOO_OffsetZero;

	LocOscillation.Y.Amplitude = CameraShakeAmplitude;
	LocOscillation.Y.Frequency = CameraShakeFrequency;
	LocOscillation.Y.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;

	LocOscillation.Z.Amplitude = CameraShakeAmplitude;
	LocOscillation.Z.Frequency = CameraShakeFrequency;
	LocOscillation.Z.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
}