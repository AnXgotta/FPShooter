#include "WeaponDataTable.generated.h"
#pragma once

USTRUCT(BlueprintType)
struct FWeaponDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	/** muzzle velocity (M/s) */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float MuzzleVelocity;

	/** Zeroing (Degrees) */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float VerticalRotation;

	/** base weapon spread (degrees) */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float WeaponSpread;

	/** targeting spread modifier */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float TargetingSpreadMod;

	/** continuous firing: spread increment */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float FiringSpreadIncrement;

	/** continuous firing: max increment */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float FiringSpreadMax;

	/** damage amount */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		int32 HitDamage;

	/** type of damage */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		TSubclassOf<UDamageType> DamageType;

	/** clip size */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		int32 AmmoPerClip;

	/** time between two consecutive shots */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float TimeBetweenShots;

	/** is weapon single fire */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		bool bSingleFire;

	/** amount to vertically displace camera on shot */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float VerticalDisplacement;

	/** amount to vertically displace camera on shot */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float HorizontalDisplacementRangeMaxAbsoluteValue;

	/** amount to vertically bounce camera */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float VerticalCameraBounceAmplitude;

	/** amplitude to shake camera */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float CameraShakeAmplitude;

	/** frequency to shake camera */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		float CameraShakeFrequency;

	/** rotate camera vertically on single shot */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		bool bDisplacementOnSingleShot;

	/** rotate camera vertically on full auto shots */
	UPROPERTY(EditAnywhere, Category = WeaponStat)
		bool bDisplacementOnFullAutoShot;

	FWeaponDataTable() {}

};