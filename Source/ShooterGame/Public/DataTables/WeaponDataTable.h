#include "ShooterTypes.h"
#include "ShooterGame.h"
#include "WeaponDataTable.generated.h"
#pragma once



USTRUCT(BlueprintType)
struct FWeaponDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditDefaultsOnly, Category = SpawnClass)
		TSubclassOf<class AShooterWeapon> SpawnClass;

	UPROPERTY(EditDefaultsOnly, Category = SpawnClass)
		TSubclassOf<class AShooterWorldActor_Weapon> WorldSpawnClass;

	/** max ammo */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		int32 MaxAmmo;

	/** clip size */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		int32 AmmoPerClip;

	/** initial clips */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		int32 InitialClips;

	/** time between two consecutive shots */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float TimeBetweenShots;

	/** failsafe reload duration if weapon doesn't have any animation for it */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float NoAnimReloadDuration;

	/** is weapon single fire */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		bool bSingleFire;

	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float Weight;

	/** muzzle velocity (M/s) */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float MuzzleVelocity;

	/** Zeroing (Degrees) */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float VerticalRotation;

	/** base weapon spread (degrees) */
	UPROPERTY(EditDefaultsOnly, Category = Accuracy)
		float WeaponSpread;

	/** targeting spread modifier */
	UPROPERTY(EditDefaultsOnly, Category = Accuracy)
		float TargetingSpreadMod;

	/** continuous firing: spread increment */
	UPROPERTY(EditDefaultsOnly, Category = Accuracy)
		float FiringSpreadIncrement;

	/** continuous firing: max increment */
	UPROPERTY(EditDefaultsOnly, Category = Accuracy)
		float FiringSpreadMax;

	/** damage amount */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		int32 HitDamage;

	/** type of damage */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		TSubclassOf<UDamageType> DamageType;

	/** hit verification: scale for bounding box of hit actor */
	UPROPERTY(EditDefaultsOnly, Category = HitVerification)
		float ClientSideHitLeeway;

	/** hit verification: threshold for dot product between view direction and hit direction */
	UPROPERTY(EditDefaultsOnly, Category = HitVerification)
		float AllowedViewDotHitDir;

	/** amount to vertically displace camera on shot */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float VerticalDisplacement;

	/** amount to vertically displace camera on shot */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float HorizontalDisplacementRangeMaxAbsoluteValue;

	/** rotate camera vertically on single shot */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		bool bDisplacementOnSingleShot;

	/** rotate camera vertically on full auto shots */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		bool bDisplacementOnFullAutoShot;

	/** defaults */
	FWeaponDataTable() {}
};