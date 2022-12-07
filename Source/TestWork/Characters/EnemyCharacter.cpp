// Fill out your copyright notice in the Description page of Project Settings.


#include "../Characters/EnemyCharacter.h"
#include "../Components/HealthComponent.h"


AEnemyCharacter::AEnemyCharacter()
{
	
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AttachWeaponMeshToSocket(*InHandSkeletalMeshComponent, "WeaponSocket");
}


