// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/ShooterWeapon.h"
#include "ShooterBallisticTrace.h"
#include "ShooterWeapon_Ballistic.generated.h"

USTRUCT()
struct FBallisticHitInfo
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		FVector Origin;

	UPROPERTY()
		FHitResult HitResult;

};

USTRUCT()
struct FBallisticWeaponData
{
	GENERATED_USTRUCT_BODY()

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

	/** defaults */
	FBallisticWeaponData()
	{
		MuzzleVelocity = 600.0f;
		VerticalRotation = 0.0f;
		WeaponSpread = 5.0f;
		TargetingSpreadMod = 0.25f;
		FiringSpreadIncrement = 1.0f;
		FiringSpreadMax = 10.0f;
		HitDamage = 10;
		DamageType = UDamageType::StaticClass();
		ClientSideHitLeeway = 200.0f;
		AllowedViewDotHitDir = 0.8f;
	}
};

UCLASS()
class SHOOTERGAME_API AShooterWeapon_Ballistic : public AShooterWeapon
{
	GENERATED_BODY()

public:

	AShooterWeapon_Ballistic();

	/** projectile class */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AShooterBallisticTrace> BallisticTraceClass;
	
protected:

	virtual EAmmoType GetAmmoType() const override
	{
		return EAmmoType::EBullet;
	}

	/** weapon config */
	UPROPERTY(EditDefaultsOnly, Category = Config)
		FBallisticWeaponData BallisticConfig;

	/** current spread from continuous firing */
	float CurrentFiringSpread;

	/** get current spread */
	float GetCurrentSpread() const;

	/** Get the aim of the weapon, allowing for adjustments to be made by the weapon */
	virtual FVector GetAdjustedAim() const override;

	/** impact effects */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<AShooterImpactEffect> ImpactTemplate;


	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() PURE_VIRTUAL(AShooterWeapon_Ballistic::FireWeapon, );

	/** spawn projectile on server */
	UFUNCTION(reliable, server, WithValidation)
	void ServerBallisticTrace(FVector Origin, FVector_NetQuantizeNormal ShootDir);

	/** [local + server] update spread on firing */
	virtual void OnBurstFinished() override;
	
public:

	void OnBulletTraceHit(const FVector Origin, const FHitResult& Impact);

protected:
	/** check if weapon should deal damage to actor */
	bool ShouldDealDamage(AActor* TestActor) const;

	/** handle damage */
	void DealDamage(const FHitResult& Impact, const FVector& ShootDir);
	
	
	//////////////////////////////////////////////////////////////////////////
	// Effects replication

	/** spawn projectile on server */
	UFUNCTION(reliable, netmulticast, WithValidation)
	void MulticastOnHitNotify(FBallisticHitInfo BHitInfo);

	/** called in network play to do the cosmetic fx  */
	void SimulateBallisticHit(const FHitResult& Impact);

	/** spawn effects for impact */
	void SpawnImpactEffects(const FHitResult& Impact);

};
