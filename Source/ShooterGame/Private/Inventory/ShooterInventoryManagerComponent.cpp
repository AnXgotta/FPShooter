// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterInventoryManagerComponent.h"


// Sets default values for this component's properties
UShooterInventoryManagerComponent::UShooterInventoryManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bReplicates = true;
	//PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UShooterInventoryManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


//// Called every frame
//void UShooterInventoryManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}



void UShooterInventoryManagerComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UShooterInventoryManagerComponent, InventorySize);

}
