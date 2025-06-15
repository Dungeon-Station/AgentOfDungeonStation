// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gimmick.h"
#include "Components/DecalComponent.h"
#include "Graffiti.generated.h"

class UDecalComponent;
class UBoxComponent;
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

	virtual void OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed) override;

	virtual void Interact_Implementation() override;
	virtual void OnBeginFocus_Implementation() override;
	virtual void OnEndFocus_Implementation() override;
private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UDecalComponent* GraffitiDecal;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* GraffitiVolumeBox;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Plane;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool GhostTrigger = false;
};
