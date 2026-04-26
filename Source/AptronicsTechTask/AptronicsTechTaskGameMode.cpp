// Copyright Epic Games, Inc. All Rights Reserved.

#include "AptronicsTechTaskGameMode.h"
#include "AptronicsTechTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAptronicsTechTaskGameMode::AAptronicsTechTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
