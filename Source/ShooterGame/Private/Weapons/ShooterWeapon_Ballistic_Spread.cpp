// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWeapon_Ballistic_Spread.h"


AShooterWeapon_Ballistic_Spread::AShooterWeapon_Ballistic_Spread() {

}


void AShooterWeapon_Ballistic_Spread::FireWeapon()
{
	const int32 RandomSeed = FMath::Rand();
	FRandomStream WeaponRandomStream(RandomSeed);
	const float CurrentSpread = GetCurrentSpread();
	const float ConeHalfAngle = FMath::DegreesToRadians(CurrentSpread * 0.5f);

	const FVector AimDir = GetAdjustedAim();
	// might want to change this to muzzle location for start of trace
	const FVector StartTrace = GetCameraDamageStartLocation(AimDir);

	for (int i = 0; i < SpreadConfig.PelletCount; i++) {
		

		const FVector ShootDir = WeaponRandomStream.VRandCone(AimDir, ConeHalfAngle, ConeHalfAngle);
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("AimDir (%f, %f, %f) | ShootDir (%f, %f, %f)"), AimDir.ToOrientationRotator().Roll, AimDir.ToOrientationRotator().Pitch, AimDir.ToOrientationRotator().Yaw, ShootDir.ToOrientationRotator().Roll, ShootDir.ToOrientationRotator().Pitch, ShootDir.ToOrientationRotator().Yaw));

		ServerBallisticTrace(StartTrace, ShootDir);

	}

	CurrentFiringSpread = FMath::Min(WeaponConfig.BallisticData.FiringSpreadMax, CurrentFiringSpread + WeaponConfig.BallisticData.FiringSpreadIncrement);

}

