// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DungeonStationGameMode.generated.h"

UCLASS(minimalapi)
class ADungeonStationGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADungeonStationGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ClearStage = 0;
};



