#pragma once

#include "ShooterUsableActorInterface.generated.h"

UINTERFACE(BlueprintType)
class UShooterUsableActorInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IShooterUsableActorInterface
{

	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IUsable")
		bool OnActorUsed(APlayerController* PlayerController);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IUsable")
		bool BeginOutlineFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IUsable")
		bool EndOutlineFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IUsable")
		bool GetIsActorUsable();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IUsable")
		FString GetUseActionText();

};
