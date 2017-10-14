#pragma once

#include "ShooterInteractableActorInterface.generated.h"

UINTERFACE(BlueprintType)
class UShooterInteractableActorInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IShooterInteractableActorInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool OnActorInteracted(AShooterCharacter* Player);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool BeginOutlineFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool EndOutlineFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		bool GetIsActorInteractable();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
		FString GetInteractActionText();

};
