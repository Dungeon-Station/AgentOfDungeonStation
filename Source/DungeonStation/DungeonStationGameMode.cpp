// Copyright Epic Games, Inc. All Rights Reserved.

#include "DungeonStationGameMode.h"
#include "DungeonStationCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeonStationGameMode::ADungeonStationGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
