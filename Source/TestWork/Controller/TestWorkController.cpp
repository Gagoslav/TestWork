// Fill out your copyright notice in the Description page of Project Settings.


#include "TestWorkController.h"
#include "../Characters/PlayerCharacter.h"

void ATestWorkController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedCharacter = Cast <APlayerCharacter>(InPawn);
	
	
}

void ATestWorkController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("Interact",IE_Pressed, this, &ATestWorkController::Interact);
		InputComponent->BindAction("Fire", IE_Pressed, this, &ATestWorkController::Fire);
		InputComponent->BindAction("Target", IE_Pressed, this, &ATestWorkController::Target);
		InputComponent->BindAction("Target", IE_Released, this, &ATestWorkController::Target);
		
	}
	
}

void ATestWorkController::Interact()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Interact();
	}
	
}

void ATestWorkController::Fire()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Fire();
	}
	
}

void ATestWorkController::Target()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Taget();
	}
}
