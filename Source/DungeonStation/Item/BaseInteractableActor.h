// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/InteractableInterface.h"
#include "BaseInteractableActor.generated.h"

class USphereComponent;

UCLASS()
class DUNGEONSTATION_API ABaseInteractableActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInteractableActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	// 아이템이 가질 Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ItemMesh;

	// 아이템이 가질 텍스트 데이터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	FText InteractionText;

	// 플레이어 인식 범위
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components | Interaction")
	USphereComponent* DetectionSphere;

	// 상호작용 가능 범위
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components | Interaction")
	USphereComponent* InteractionSphere;

protected:
	// 플레이어 인식 범위 안에 있는지 여부
	bool bIsPlayerInDetectionRange;
	// 상호작용 범위 안에 있는지 여부
	bool bIsPlayerInInteractionRange;

	// 이벤트 함수
	// DetectionSphere 이벤트
	UFUNCTION()
	void OnDetectionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweeepResult);
	UFUNCTION()
	void OnDetectionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// InteractionSphere 이벤트
	UFUNCTION()
	void OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// UI 헬퍼 함수
	void UpdateInteractionUI();
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
