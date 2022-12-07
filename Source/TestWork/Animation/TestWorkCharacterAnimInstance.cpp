// Fill out your copyright notice in the Description page of Project Settings.


#include "../Animation/TestWorkCharacterAnimInstance.h"
#include "../Characters//PlayerCharacter.h"

void UTestWorkCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	if (TryGetPawnOwner()->IsA<APlayerCharacter>())
	{
		CachedPlayerCharacter = StaticCast<APlayerCharacter*>(TryGetPawnOwner());
	}
}

void UTestWorkCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	if (IsValid(CachedPlayerCharacter))
	{
		bIsTargeting = CachedPlayerCharacter->GetIsTargeting();
	}
}
