// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gimmick.generated.h"

UCLASS()
class DUNGEONSTATION_API AGimmick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGimmick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	FORCEINLINE void SetIsGimmickCleared(bool bIsCleared) { bIsGimmickCleared = bIsCleared; }
	FORCEINLINE bool GetIsGimmickCleared() const { return bIsGimmickCleared; }

private:
	bool bIsGimmickCleared = false;

};
