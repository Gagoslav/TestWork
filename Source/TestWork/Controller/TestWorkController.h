// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestWorkController.generated.h"

/**
 * 
 */
UCLASS()
class TESTWORK_API ATestWorkController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void SetPawn(APawn* InPawn) override;

protected:
	
	virtual void SetupInputComponent() override;

	void Interact();
	void Fire();
	void Target();
	
private:
	TSoftObjectPtr<class APlayerCharacter> CachedCharacter;
};
