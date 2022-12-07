// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"

// Component is designed to pass the bool value for player character as well as for
// other characters if they can interact with item

class AInteractableActorBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTWORK_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	

	UFUNCTION(BlueprintCallable)
	inline bool CanInteract() { return bCanInteract; }

	UFUNCTION()
	void SetIsInteractable(bool NewInteractable);

	
	UFUNCTION(BlueprintCallable)
	inline AInteractableActorBase* GetInteractableActor() { return ThisInteractableActor; }

	UFUNCTION()
	void SetInteractableActor(AInteractableActorBase* NewActor);

protected:
	virtual void BeginPlay();

private:
	bool bCanInteract = 0;
	AInteractableActorBase* ThisInteractableActor;


		
};
