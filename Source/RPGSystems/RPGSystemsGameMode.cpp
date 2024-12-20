// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGSystemsGameMode.h"
#include "Character/RPGSystemsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGSystemsGameMode::ARPGSystemsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
