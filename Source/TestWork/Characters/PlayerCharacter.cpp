// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "../Components/InteractableComponent.h"
#include "../Interactable/InteractableActorBase.h"
#include "../Interactable/Weapon.h"
#include "../Components/HealthComponent.h"
#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"




// Called when the game starts or when spawned




void APlayerCharacter::Interact()
{
	// if we already are allowed to interact with some interactable item
	// InteractableComponent's reference is initialized in base class ATestWorkCharacter

	if (InteractableComponent->CanInteract() && InteractableComponent->GetInteractableActor() != nullptr)
	{
		// Set the weapon mesh (skeletal mesh that is attached to our character) to the one of the interactable actor's
		// skeletal mesh component
		USkeletalMesh* WeaponSkeletalMesh = InteractableComponent->GetInteractableActor()->GetSkeletalMeshComponent()->SkeletalMesh;
		USkeletalMeshComponent* WeaponSkeletalMeshComponent = InteractableComponent->GetInteractableActor()->GetSkeletalMeshComponent();
		SetWeaponMesh(WeaponSkeletalMesh);

		// TODO correct the weapon position, attach it to the socket "WeaponSocket"
		AttachWeaponMeshToSocket(*InHandSkeletalMeshComponent, "WeaponSocket");


		// After we have cached the value of skeletal mesh just delete the interactable actor
		CachedInteractableActor = InteractableComponent->GetInteractableActor();
		InteractableComponent->GetInteractableActor()->ConditionalBeginDestroy();

	}

}

void APlayerCharacter::Fire()
{
	if (IsValid(CachedInteractableActor) && IsInteractableActorWeapon(CachedInteractableActor))
	{

		FHitResult HitResult;
		FVector Start = InHandSkeletalMeshComponent->GetBoneLocation("Muzzle");
		FVector Direction = InHandSkeletalMeshComponent->GetRightVector();

		//ShootingDistance is already initialized in IsInteractableActorWeapo method
		FVector End = Start + Direction * ShootingDistance;
		FCollisionQueryParams QueryParams;
		TArray<AActor*> ActorsToIgnore;

		if (UKismetSystemLibrary::LineTraceSingle(GetWorld(), Start, End, ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true))
		{
			// Check if the actor we are shooting is an enemy
			if (HitResult.GetActor()->GetClass()->GetSuperClass()->GetName().Equals("EnemyCharacter"))
			{
				TSoftObjectPtr<AEnemyCharacter>Enemy = StaticCast<AEnemyCharacter*>(HitResult.GetActor());
				Enemy->HealthComponent->ApplyDamage(WeaponPower);
				if (Enemy.IsValid())
					GEngine->AddOnScreenDebugMessage(1, 1.0, FColor::Red, FString::Printf(TEXT("Enemy HP is %f"), Enemy->HealthComponent->Health));

			}


		}
	}
}



void APlayerCharacter::Taget()
{
	if (IsValid(CachedInteractableActor))
	{
		if (IsInteractableActorWeapon(CachedInteractableActor))
		{
			bIsTargeting = !bIsTargeting;
			
		}
	}
}

bool APlayerCharacter::IsInteractableActorWeapon(AInteractableActorBase* InteractableActor)
{
	if (InteractableActor->IsA<AWeapon>())
	{
		// Shooting distance should be initialized in Weapon object
		ShootingDistance = StaticCast<AWeapon*>(InteractableActor)->WeaponShootRange;
		WeaponPower = StaticCast<AWeapon*>(InteractableActor)->WeaponPower;
		return true;
	}
	return false;
}



void APlayerCharacter::SetWeaponMesh(USkeletalMesh* NewMesh)
{
	// Simply initializes the skeletal mesh of our character's weapon skeletal mesh component
	InHandSkeletalMeshComponent->SetSkeletalMesh(NewMesh, true);
}



