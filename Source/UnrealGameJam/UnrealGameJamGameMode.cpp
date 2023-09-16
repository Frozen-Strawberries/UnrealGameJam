// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealGameJamGameMode.h"
#include "UnrealGameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealGameJamGameMode::AUnrealGameJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
