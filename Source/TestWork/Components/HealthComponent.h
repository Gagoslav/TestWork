// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTWORK_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health settings")
	float Health = 100.0f;
	
	UFUNCTION(BlueprintCallable)
	void ApplyDamage(float NewDamage);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

	

		
};
