// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/InteractableInterface.h"
#include "BaseInteractableActor.generated.h"


UCLASS()
class DUNGEONSTATION_API ABaseInteractableActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInteractableActor();

	// 아이템이 가질 Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ItemMesh;

	// 아이템이 가질 텍스트 데이터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	FText InterationText;

public:
	// 인터페이스 함수의 기본 함수 정의
	virtual void OnBeginFocus_Implementation() override;
	virtual void OnEndFocus_Implementation() override;
	virtual FText GetInteractionText_Implementation() override;
	virtual void Interact_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
