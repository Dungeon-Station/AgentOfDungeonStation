// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Gimmick/Gimmick.h"
#include "ItemPhone.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSTATION_API AItemPhone : public AGimmick
{
	GENERATED_BODY()

public:
	AItemPhone();

public:
	virtual void Interact_Implementation() override;
};
