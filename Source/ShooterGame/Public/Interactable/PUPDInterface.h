// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PUPDInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPUPDInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTERGAME_API IPUPDInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void OnPickUp() = 0;
	virtual void OnPutDown() = 0;
	
};
