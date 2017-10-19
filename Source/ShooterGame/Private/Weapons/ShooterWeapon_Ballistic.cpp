// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "Effects/ShooterImpactEffect.h"
#include "ShooterWeapon_Ballistic.h"



AShooterWeapon_Ballistic::AShooterWeapon_Ballistic() {
	CurrentFiringSpread = 0.0f;
	WeaponConfig.BallisticData.MuzzleVelocity = WeaponConfig.BallisticData.MuzzleVelocity * 100.0f;
}


//////////////////////////////////////////////////////////////////////////
// Weapon usage



bool AShooterWeapon_Ballistic::ServerBallisticTrace_Validate(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	return true;
}

void AShooterWeapon_Ballistic::ServerBallisticTrace_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	FTransform SpawnTM(ShootDir.ToOrientationRotator(), Origin);		
	
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("Start Spawn Ballistic Actor | Origin: (%f, %f, %f) | ShootDir: (%f, %f, %f)"), Origin.X, Origin.Y, Origin.Z, ShootDir.X, ShootDir.Y, ShootDir.Z));

	AShooterBallisticTrace* Projectile = Cast<AShooterBallisticTrace>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, BallisticTraceClass, SpawnTM));
	if (Projectile)
	{
		Projectile->Instigator = Instigator;
		Projectile->SetOwner(this);
		Projectile->InitializeValues(WeaponConfig.BallisticData.MuzzleVelocity);
		UGameplayStatics::FinishSpawningActor(Projectile, SpawnTM);
	}
}


void AShooterWeapon_Ballistic::OnBurstFinished()
{
	Super::OnBurstFinished();

	CurrentFiringSpread = 0.0f;
}



void AShooterWeapon_Ballistic::OnBulletTraceHit(const FVector Origin, const FHitResult& Impact) {

	// handle damage
	if (ShouldDealDamage(Impact.GetActor()))
	{
		DealDamage(Impact, -Impact.Normal);
	}

	// play FX on remote clients
	if (Role == ROLE_Authority)
	{
		//HitNotify.Origin = Origin;
		//HitNotify.HitResult = Impact;
		FBallisticHitInfo BHitInfo;
		BHitInfo.Origin = Origin;
		BHitInfo.HitResult = Impact;

		MulticastOnHitNotify(BHitInfo);
	}

}

bool AShooterWeapon_Ballistic::ShouldDealDamage(AActor* TestActor) const
{
	// if we're an actor on the server, or the actor's role is authoritative, we should register damage
	if (TestActor)
	{
		if (GetNetMode() != NM_Client || TestActor->Role == ROLE_Authority || TestActor->bTearOff)
		{
			return true;
		}
	}

	return false;
}

void AShooterWeapon_Ballistic::DealDamage(const FHitResult& Impact, const FVector& ShootDir)
{
	FPointDamageEvent PointDmg;
	PointDmg.DamageTypeClass = WeaponConfig.BallisticData.DamageType;
	PointDmg.HitInfo = Impact;
	PointDmg.ShotDirection = ShootDir;
	PointDmg.Damage = WeaponConfig.BallisticData.HitDamage;

	Impact.GetActor()->TakeDamage(PointDmg.Damage, PointDmg, MyPawn->Controller, this);
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage helpers

FVector AShooterWeapon_Ballistic::GetAdjustedAim() const {
	FVector finalAim = Super::GetAdjustedAim();
	finalAim.ToOrientationRotator().Add(WeaponConfig.BallisticData.VerticalRotation, 0.0f, 0.0f);
	return finalAim;

}

float AShooterWeapon_Ballistic::GetCurrentSpread() const
{
	float FinalSpread = WeaponConfig.BallisticData.WeaponSpread + CurrentFiringSpread;
	if (MyPawn && MyPawn->IsTargeting())
	{
		FinalSpread *= WeaponConfig.BallisticData.TargetingSpreadMod;
	}

	return FinalSpread;
}



//////////////////////////////////////////////////////////////////////////
// Replication & effects

bool AShooterWeapon_Ballistic::MulticastOnHitNotify_Validate(FBallisticHitInfo BHitInfo) {
	return true;
}

void AShooterWeapon_Ballistic::MulticastOnHitNotify_Implementation(FBallisticHitInfo BHitInfo) {
	// if we're an actor on the server, don't spawn effects
	if (GetNetMode() != NM_Client) {
		return;
	}
	SimulateBallisticHit(BHitInfo.HitResult);
}

void AShooterWeapon_Ballistic::SimulateBallisticHit(const FHitResult& Impact)
{
	SpawnImpactEffects(Impact);
}

void AShooterWeapon_Ballistic::SpawnImpactEffects(const FHitResult& Impact)
{
	if (ImpactTemplate && Impact.bBlockingHit)
	{
		FHitResult UseImpact = Impact;

		FTransform const SpawnTransform(Impact.ImpactNormal.Rotation(), Impact.ImpactPoint);
		AShooterImpactEffect* EffectActor = GetWorld()->SpawnActorDeferred<AShooterImpactEffect>(ImpactTemplate, SpawnTransform);
		if (EffectActor)
		{
			EffectActor->SurfaceHit = UseImpact;
			UGameplayStatics::FinishSpawningActor(EffectActor, SpawnTransform);
		}
	}
}

//void AShooterWeapon_Ballistic::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
//{
//	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//}