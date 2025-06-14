// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Gimmick/Gimmick.h"
#include "ItemWallet.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSTATION_API AItemWallet : public AGimmick
{
	GENERATED_BODY()
	
public:
	AItemWallet();

public:
	virtual void Interact_Implementation() override;
};
