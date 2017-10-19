// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterWeapon.h"
#include "ShooterTypes.h"
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
