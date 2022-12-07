// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponent.h"
#include "../Interactable/InteractableActorBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties

void UInteractableComponent::SetIsInteractable(bool NewInteractable)
{
	bCanInteract = NewInteractable;
	
}

void UInteractableComponent::SetInteractableActor(AInteractableActorBase* NewActor)
{
	ThisInteractableActor = NewActor;

}

void UInteractableComponent::BeginPlay()
{
	Super::BeginPlay();
	TSubclassOf<AInteractableActorBase>ClassToFind;
	ClassToFind = AInteractableActorBase::StaticClass();
	TArray<AActor*>ArrayOfInteractableActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, ArrayOfInteractableActors);
	for (AActor* Actor : ArrayOfInteractableActors)
	{
		AInteractableActorBase* InteractableActor = StaticCast<AInteractableActorBase*>(Actor);
		InteractableActor->OnEnableInteraction.AddUObject(this, &UInteractableComponent::SetIsInteractable);
		
	}
}
