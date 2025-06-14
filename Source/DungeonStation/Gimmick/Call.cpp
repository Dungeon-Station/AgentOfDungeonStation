// Fill out your copyright notice in the Description page of Project Settings.


#include "Call.h"
#include "Components/BoxComponent.h"
#include "Train/TrainManager.h"
#include "Kismet/GameplayStatics.h"

ACall::ACall()
{
	CallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Call"));
	SetRootComponent(CallMesh);

	CallMesh->SetCustomDepthStencilValue(2);
}


void ACall::BeginPlay()
{

}

void ACall::Tick(float DeltaTime)
{
}

void ACall::Interact_Implementation()
{
	for (auto Gimmick : Gimmicks)
	{
		if (!Gimmick->GetIsGimmickCleared())
		{
			if (FailSound)
				UGameplayStatics::PlaySoundAtLocation(this, FailSound, GetActorLocation());
			return;
		}
	}
	if (ClearSound)
		UGameplayStatics::PlaySoundAtLocation(this, ClearSound, GetActorLocation());
	TrainManager->ClearStage();
}

void ACall::OnBeginFocus_Implementation()
{
	if (CallMesh)
	{
		CallMesh->SetRenderCustomDepth(true); // 하이라이트 켜기
	}
}

void ACall::OnEndFocus_Implementation()
{
	if (CallMesh)
	{
		CallMesh->SetRenderCustomDepth(false); // 하이라이트 켜기
	}
}

void ACall::OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	for (auto Gimmick : Gimmicks)
	{
		if (!Gimmick->GetIsGimmickCleared())
		{
			if (FailSound)
				UGameplayStatics::PlaySoundAtLocation(this, FailSound, GetActorLocation());
			return;
		}
	}
	if (ClearSound)
		UGameplayStatics::PlaySoundAtLocation(this, ClearSound, GetActorLocation());
	TrainManager->ClearStage();
}