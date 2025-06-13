// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteractableActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ABaseInteractableActor::ABaseInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(RootComponent);
	ItemMesh->SetCollisionResponseToChannel(ECC_Visibility, ECollisionResponse::ECR_Block);
	ItemMesh->SetCustomDepthStencilValue(2);

	// 인식 범위
	DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	DetectionSphere->SetupAttachment(RootComponent);
	DetectionSphere->SetSphereRadius(1000.0f);
	DetectionSphere->SetCollisionProfileName(TEXT("Trigger"));

	// 상호작용 범위
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(RootComponent);
	InteractionSphere->SetSphereRadius(200.0f);
	InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));

	// 기본값 설정
	InteractionText = FText::FromString(TEXT("상호작용"));
	bIsPlayerInDetectionRange = false;
	bIsPlayerInInteractionRange = false;
}

void ABaseInteractableActor::OnDetectionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweeepResult)
{
	if (OtherActor)
	{
		bIsPlayerInDetectionRange = true;
	}
}

void ABaseInteractableActor::OnDetectionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		bIsPlayerInDetectionRange = false;
		// 인식 범위를 벗어나면 모든 시각적 피드백 제거
		OnEndFocus_Implementation();
	}
}

void ABaseInteractableActor::OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		bIsPlayerInInteractionRange = true;
		// 상호작용 범위로 들어왔을 때, 이미 포커스 상태라면 UI를 바로 업데이트 
		UpdateInteractionUI();
	}
}

void ABaseInteractableActor::OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		bIsPlayerInInteractionRange = false;
		// 상호작용 범위를 벗어나면 UI를 바로 업데이트 (숨김 처리)
		UpdateInteractionUI();
	}
}

void ABaseInteractableActor::UpdateInteractionUI()
{
	 // Text UI를 보주는 조건: 플레이어가 상호작용 범위 안에 있고, 현재 이 익터에 포커스 되어있을 때 
	const bool bIsFocused = (ItemMesh && ItemMesh->bRenderCustomDepth); // Custom Depth를 사용하여 포커스 상태 확인

	if (bIsPlayerInInteractionRange && bIsFocused)
	{
		// TODO : TEXT UI 보이도록 렌더링
	}
	else
	{
		// TODO : TEXT UI 숨김 처리
	}
}

void ABaseInteractableActor::OnBeginFocus_Implementation()
{
	if (bIsPlayerInDetectionRange && ItemMesh)
	{
		ItemMesh->SetRenderCustomDepth(true); // 하이라이트 켜기
		UpdateInteractionUI(); // UI 상태 업데이트
	}
}

void ABaseInteractableActor::OnEndFocus_Implementation()
{
	if (bIsPlayerInDetectionRange && ItemMesh)
	{
		ItemMesh->SetRenderCustomDepth(false); // 하이라이트 끄기
		UpdateInteractionUI(); // UI 상태 업데이트
	}
}

FText ABaseInteractableActor::GetInteractionText_Implementation()
{
	return InteractionText;
}

void ABaseInteractableActor::Interact_Implementation()
{

	// 상호 작용 범위 안에 있는지 확인하고 실행
	// 자식 클래스에서 내용 구현 
	if (bIsPlayerInInteractionRange)
	{
	}
}

// Called when the game starts or when spawned
void ABaseInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 각 Sphere의 이벤트에 맞는 함수 바인딩
	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABaseInteractableActor::OnDetectionSphereBeginOverlap);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &ABaseInteractableActor::OnDetectionSphereEndOverlap);

	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABaseInteractableActor::OnInteractionSphereBeginOverlap);
	InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &ABaseInteractableActor::OnInteractionSphereEndOverlap);
}

// Called every frame
void ABaseInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

