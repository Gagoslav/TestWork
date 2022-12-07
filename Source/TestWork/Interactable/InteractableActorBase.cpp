// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActorBase.h"
#include "Components/BoxComponent.h"
#include "../Components/InteractableComponent.h"
#include "../TestWorkCharacter.h"


AInteractableActorBase::AInteractableActorBase()
{
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionComponent->SetupAttachment(RootComponent);
	CollisionComponent->SetBoxExtent(BoxInitialExtension);
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	SkeletalMesh = CreateDefaultSubobject <USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->AttachToComponent(CollisionComponent, FAttachmentTransformRules::KeepRelativeTransform);

	
}

void AInteractableActorBase::SetIsPawnInside(bool IsInside)
{
	bIsPawnInside = IsInside;
}

void AInteractableActorBase::BeginPlay()
{
	Super::BeginPlay();
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActorBase::BeginOverlap);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AInteractableActorBase::EndOverlap);
	
}

void AInteractableActorBase::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	//when we overlapped the box of interactable actor we can take the item
	if (OtherActor->IsA<ATestWorkCharacter>())
	{
		CachedCharacter = StaticCast <ATestWorkCharacter*>(OtherActor);
		CachedCharacter->InteractableComponent->SetInteractableActor(this);
		SetIsPawnInside(true);
		OnEnableInteraction.Broadcast(GetIsPawnInside());
		
	}
	
	
}

void AInteractableActorBase::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
	//we cannot take the interactable item any longer
	if (OtherActor->IsA<APawn>())
	{
		CachedCharacter->InteractableComponent->SetInteractableActor(nullptr);
		SetIsPawnInside(false);
		OnEnableInteraction.Broadcast(GetIsPawnInside());
	}
}


