// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ShooterTypes.generated.h"
#pragma once

namespace EShooterMatchState
{
	enum Type
	{
		Warmup,
		Playing,
		Won,
		Lost,
	};
}

namespace EShooterCrosshairDirection
{
	enum Type
	{
		Left=0,
		Right=1,
		Top=2,
		Bottom=3,
		Center=4
	};
}

namespace EShooterHudPosition
{
	enum Type
	{
		Left=0,
		FrontLeft=1,
		Front=2,
		FrontRight=3,
		Right=4,
		BackRight=5,
		Back=6,
		BackLeft=7,
	};
}

/** keep in sync with ShooterImpactEffect */
UENUM()
namespace EShooterPhysMaterialType
{
	enum Type
	{
		Unknown,
		Concrete,
		Dirt,
		Water,
		Metal,
		Wood,
		Grass,
		Glass,
		Flesh,
	};
}

namespace EShooterDialogType
{
	enum Type
	{
		None,
		Generic,
		ControllerDisconnected
	};
}

#define SHOOTER_SURFACE_Default		SurfaceType_Default
#define SHOOTER_SURFACE_Concrete	SurfaceType1
#define SHOOTER_SURFACE_Dirt		SurfaceType2
#define SHOOTER_SURFACE_Water		SurfaceType3
#define SHOOTER_SURFACE_Metal		SurfaceType4
#define SHOOTER_SURFACE_Wood		SurfaceType5
#define SHOOTER_SURFACE_Grass		SurfaceType6
#define SHOOTER_SURFACE_Glass		SurfaceType7
#define SHOOTER_SURFACE_Flesh		SurfaceType8

USTRUCT()
struct FDecalData
{
	GENERATED_USTRUCT_BODY()

	/** material */
	UPROPERTY(EditDefaultsOnly, Category=Decal)
	UMaterial* DecalMaterial;

	/** quad size (width & height) */
	UPROPERTY(EditDefaultsOnly, Category=Decal)
	float DecalSize;

	/** lifespan */
	UPROPERTY(EditDefaultsOnly, Category=Decal)
	float LifeSpan;

	/** defaults */
	FDecalData()
		: DecalSize(256.f)
		, LifeSpan(10.f)
	{
	}
};

/** replicated information on a hit we've taken */
USTRUCT()
struct FTakeHitInfo
{
	GENERATED_USTRUCT_BODY()

	/** The amount of damage actually applied */
	UPROPERTY()
	float ActualDamage;

	/** The damage type we were hit with. */
	UPROPERTY()
	UClass* DamageTypeClass;

	/** Who hit us */
	UPROPERTY()
	TWeakObjectPtr<class AShooterCharacter> PawnInstigator;

	/** Who actually caused the damage */
	UPROPERTY()
	TWeakObjectPtr<class AActor> DamageCauser;

	/** Specifies which DamageEvent below describes the damage received. */
	UPROPERTY()
	int32 DamageEventClassID;

	/** Rather this was a kill */
	UPROPERTY()
	uint32 bKilled:1;

private:

	/** A rolling counter used to ensure the struct is dirty and will replicate. */
	UPROPERTY()
	uint8 EnsureReplicationByte;

	/** Describes general damage. */
	UPROPERTY()
	FDamageEvent GeneralDamageEvent;

	/** Describes point damage, if that is what was received. */
	UPROPERTY()
	FPointDamageEvent PointDamageEvent;

	/** Describes radial damage, if that is what was received. */
	UPROPERTY()
	FRadialDamageEvent RadialDamageEvent;

public:
	FTakeHitInfo();

	FDamageEvent& GetDamageEvent();
	void SetDamageEvent(const FDamageEvent& DamageEvent);
	void EnsureReplication();
};

USTRUCT()
struct FWeaponRecoil
{
	GENERATED_USTRUCT_BODY()

		/** amount to vertically displace camera on shot */
		UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float VerticalDisplacement;

	/** amount to vertically displace camera on shot */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float HorizontalDisplacementRangeMaxAbsoluteValue;

	/** amount to vertically bounce camera */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float VerticalCameraBounceAmplitude;

	/** amplitude to shake camera */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float CameraShakeAmplitude;

	/** frequency to shake camera */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		float CameraShakeFrequency;

	/** rotate camera vertically on single shot */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		bool bDisplacementOnSingleShot;

	/** rotate camera vertically on full auto shots */
	UPROPERTY(EditDefaultsOnly, Category = WeaponRecoil)
		bool bDisplacementOnFullAutoShot;

	/** defaults */
	FWeaponRecoil()
	{
		VerticalDisplacement = 2.0f;
		HorizontalDisplacementRangeMaxAbsoluteValue = 1.0f;
		VerticalCameraBounceAmplitude = 20.0f;
		CameraShakeAmplitude = 0.3f;
		CameraShakeFrequency = 50.0f;
		bDisplacementOnSingleShot = false;
		bDisplacementOnFullAutoShot = true;
	}
};

USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

		/** inifite ammo for reloads */
		UPROPERTY(EditDefaultsOnly, Category = Ammo)
		bool bInfiniteAmmo;

	/** infinite ammo in clip, no reload required */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		bool bInfiniteClip;

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

	/** Weapon recoil information */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		FWeaponRecoil WeaponRecoil;

	/** defaults */
	FWeaponData()
	{
		bInfiniteAmmo = false;
		bInfiniteClip = false;
		MaxAmmo = 100;
		AmmoPerClip = 20;
		InitialClips = 4;
		TimeBetweenShots = 0.2f;
		NoAnimReloadDuration = 1.0f;
		bSingleFire = false;
		WeaponRecoil = FWeaponRecoil();
	}
};

USTRUCT(BlueprintType)
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

UENUM(BlueprintType)
namespace EShooterItemType
{
	enum Type
	{
		Weapon,
		WeaponAttachment,
		Consumable,
		Ammo
	};
}

USTRUCT(BlueprintType)
struct FShooterInventoryItem
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		FName ID;

	UPROPERTY()
		UTexture2D* Icon;

	UPROPERTY()
		FName Name;

	UPROPERTY()
		FString Description;

	UPROPERTY()
		TEnumAsByte<EShooterItemType::Type> ItemType;

	UPROPERTY()
		int8 Amount; // -127 to 127

	UPROPERTY()
		bool bIsStackable;

	UPROPERTY()
		int8 MaxStackable; // -127 to 127

public:
	FShooterInventoryItem() {

	}

};

USTRUCT(BlueprintType)
struct FInventorySlotInformation
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		TEnumAsByte<EShooterItemType::Type> ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		int Amount;


public:
	FInventorySlotInformation() {

	}

};

USTRUCT(BlueprintType)
struct FInventoryItemToolTip
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		UTexture2D* Icon;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		FName Name;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
			FString Description;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
			TEnumAsByte<EShooterItemType::Type> ItemType;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
			int Amount;


public:
	FInventoryItemToolTip() {

	}

};

USTRUCT(BlueprintType)
struct FShooterInventoryContainer
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		bool bIsStorageContainer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		float MaxWeight;

public:
	FShooterInventoryContainer() {

	}

};