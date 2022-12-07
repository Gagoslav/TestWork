// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestWorkCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTWORK_API UTestWorkCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TargetSetting")
	bool bIsTargeting = 0;
	
protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation (float DeltaTime) override;

private:
	class APlayerCharacter* CachedPlayerCharacter;

};
