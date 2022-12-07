// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActorBase.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEnableInteraction, bool);


UCLASS()
class TESTWORK_API AInteractableActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AInteractableActorBase();

	//Declare delegate to bind and execute it as the character enters the area of interaction
	FOnEnableInteraction OnEnableInteraction;

	//make getter and setter for bIsPawnInside field
	inline bool GetIsPawnInside() { return bIsPawnInside; }
	void SetIsPawnInside(bool IsInside);

	inline USkeletalMeshComponent* GetSkeletalMeshComponent() { return SkeletalMesh; }

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* CollisionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USkeletalMeshComponent* SkeletalMesh;

	
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	

private:
	FVector BoxInitialExtension = FVector(100.0f, 100.0f, 100.0f);
	USceneComponent* Scene;
	bool bIsPawnInside = 0;
	class ATestWorkCharacter* CachedCharacter;
};
