// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestWorkGameMode.h"
#include "TestWorkCharacter.h"
#include "UObject/ConstructorHelpers.h"

//ATestWorkGameMode::ATestWorkGameMode()
//{
//	// set default pawn class to our Blueprinted character
//	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
//	if (PlayerPawnBPClass.Class != NULL)
//	{
//		DefaultPawnClass = PlayerPawnBPClass.Class;
//	}
//}


// When I changed the default ThirdPersonCharacter template I faced a bug that editor couldn't open the 
// project and got stack on 75%
