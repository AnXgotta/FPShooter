// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterWidgetBase.h"



void UShooterWidgetBase::NativePreConstruct()
{
	if (AShooterPlayerController* MyPC = Cast<AShooterPlayerController>(GetOwningPlayer()))
	{
		OwningController = MyPC;
	}
	Super::NativePreConstruct();
}
void UShooterWidgetBase::NativeConstruct()
{
	if (AShooterPlayerController* MyPC = Cast<AShooterPlayerController>(GetOwningPlayer()))
	{
		OwningController = MyPC;
	}
	Super::NativeConstruct();
}
