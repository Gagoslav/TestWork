// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TestWorkCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTWORK_API AEnemyCharacter : public ATestWorkCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();
	
protected:
	virtual void BeginPlay() override;
	
};
