// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/InteractableInterface.h"
#include "BaseInteractableActor.generated.h"

class USphereComponent;

UCLASS(Abstract)
class DUNGEONSTATION_API ABaseInteractableActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInteractableActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	// 아이템이 가질 Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ItemMesh;

	// 아이템이 가질 텍스트 데이터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	FText InteractionText;

	// 이 물체를 인식하고 하이라이팅 할 수 있는 최대 거리
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction", meta = (ClampMin = "0.0"))
	float DetectionDistance;

	// 플레이어가 상호작용할 수 있는 최대 거리 (UI 표시 및 실행)
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Interaction", meta = (ClampMin = "0.0"))
	float InteractionDistance;

protected:
	// 플레이어 인식 범위 안에 있는지 여부
	bool bIsPlayerInDetectionRange;
	// 상호작용 범위 안에 있는지 여부
	bool bIsPlayerInInteractionRange;

public:
	// 인터페이스 함수의 기본 함수 정의

	virtual void OnBeginFocus_Implementation() override;
	virtual void OnEndFocus_Implementation() override;
	virtual FText GetInteractionText_Implementation() override;
	virtual void Interact_Implementation() override;

};
