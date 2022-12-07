// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TestWorkCharacter.h"
#include "PlayerCharacter.generated.h"



UCLASS()
class TESTWORK_API APlayerCharacter : public ATestWorkCharacter
{
	GENERATED_BODY()

public:
	

	UFUNCTION(BlueprintCallable)
	inline bool GetIsTargeting() { return bIsTargeting; }
	
	virtual void Interact();

	virtual void Fire();

	void Taget();

	void SetWeaponMesh(USkeletalMesh* NewMesh);

	bool IsInteractableActorWeapon(class AInteractableActorBase* InteractableActor);

	

private:

	float ShootingDistance = 0.0f;
	float WeaponPower = 0.0f;
	AInteractableActorBase* CachedInteractableActor;
	
	bool bIsTargeting = 0;
	
};
