// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactable/InteractableActorBase.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class TESTWORK_API AWeapon : public AInteractableActorBase
{
	GENERATED_BODY()

public :

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon params")
		float WeaponShootRange = 1000.0f;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon params")
		float WeaponPower = 10.0f;
};
