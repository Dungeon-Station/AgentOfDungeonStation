// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gimmick.h"
#include "Call.generated.h"

/**
 * 
 */
class UBoxComponent;
class ATrainManager;
UCLASS()
class DUNGEONSTATION_API ACall : public AGimmick
{
	GENERATED_BODY()
	
public:
	ACall();

	virtual void OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CallMesh = nullptr;

	UPROPERTY()
	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AGimmick*> Gimmicks;

	UPROPERTY(EditDefaultsOnly, Category = "Door")
	TSubclassOf<AActor> BlueprintToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ATrainManager* TrainManager = nullptr;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* ClearSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* FailSound;
};
