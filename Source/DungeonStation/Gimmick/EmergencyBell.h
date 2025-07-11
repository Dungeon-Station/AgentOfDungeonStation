// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gimmick.h"
#include "EmergencyBell.generated.h"


UCLASS()
class DUNGEONSTATION_API AEmergencyBell : public AGimmick
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmergencyBell();

	virtual void OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
	virtual void OnBeginFocus_Implementation() override;
	virtual void OnEndFocus_Implementation() override;
private:
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* NormalBellSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* AbnormalBellSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	float NormalBellRatio = 0.5f;

	UPROPERTY()
	UAudioComponent* NormalAudioComponent;

	UPROPERTY()
	UAudioComponent* AbnormalAudioComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* BellMesh;

};
