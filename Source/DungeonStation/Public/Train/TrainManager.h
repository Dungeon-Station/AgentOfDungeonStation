// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrainManager.generated.h"

class AGimmick;
class UBoxComponent;
class USpotLightComponent;
UCLASS()
class DUNGEONSTATION_API ATrainManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrainManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	TArray<AGimmick*> Gimmicks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* StartTrigger;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float AccTime = 0.0;

};
