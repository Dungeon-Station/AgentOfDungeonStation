// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Item/BaseInteractableActor.h"
#include "Memo.generated.h"

UCLASS()
class DUNGEONSTATION_API AMemo : public ABaseInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
	virtual void OnBeginFocus_Implementation() override;
	virtual void OnEndFocus_Implementation() override;
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Memo = nullptr;
};
