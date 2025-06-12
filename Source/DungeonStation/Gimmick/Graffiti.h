// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gimmick.h"
#include "Graffiti.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSTATION_API AGraffiti : public AGimmick
{
	GENERATED_BODY()
	
public:
	AGraffiti();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* GraffitiMesh;
};
