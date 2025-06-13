// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteractableActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ABaseInteractableActor::ABaseInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(RootComponent);
	ItemMesh->SetCollisionResponseToChannel(ECC_Visibility, ECollisionResponse::ECR_Block);
	ItemMesh->SetCustomDepthStencilValue(2);

	// 기본값 설정
	InteractionText = FText::FromString(TEXT("상호작용하세요"));
	bIsPlayerInDetectionRange = false;
	bIsPlayerInInteractionRange = false;
	DetectionDistance = 800.0f; // 기본 인식 거리
	InteractionDistance = 200.0f; // 기본 상호작용 거리
}


void ABaseInteractableActor::OnBeginFocus_Implementation()
{
	if (ItemMesh)
	{
		ItemMesh->SetRenderCustomDepth(true); // 하이라이트 켜기
	}
}

void ABaseInteractableActor::OnEndFocus_Implementation()
{
	if (ItemMesh)
	{
		ItemMesh->SetRenderCustomDepth(false); // 하이라이트 끄기
	}
}

FText ABaseInteractableActor::GetInteractionText_Implementation()
{
	return InteractionText;
}

void ABaseInteractableActor::Interact_Implementation()
{
	// 기본 상호작용로직을 여기에 구현
	// 특정	아이템의 경우 이 함수를 오버라이드하여 구체적인 상호작용을 구현할 수 있습니다.
}


