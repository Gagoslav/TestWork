// Fill out your copyright notice in the Description page of Project Settings.


#include "../Components/HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "../Characters/PlayerCharacter.h"

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UHealthComponent::ApplyDamage(float NewDamage)
{
	// Reduce health amount
	Health -= NewDamage;
	if (Health <= 0)
	{
		GetOwner()->ConditionalBeginDestroy();
		
	}
}





