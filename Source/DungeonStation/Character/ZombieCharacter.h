// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Interface/InteractableInterface.h"

#include "ZombieCharacter.generated.h"

UCLASS()
class DUNGEONSTATION_API AZombieCharacter : public ACharacter, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "ZombieCharacter")
	void TriggerZombieAnimation();

	virtual void OnBeginFocus_Implementation() override;
	virtual void OnEndFocus_Implementation() override;
	virtual FText GetInteractionText_Implementation() override;
	virtual void Interact_Implementation() override;
private:
	bool bIsTriggered = false;
	bool bIsNeckRotateFinished = false;
	bool bIsHeadRotateFinished = false;
};
