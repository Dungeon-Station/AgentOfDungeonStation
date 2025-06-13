// Fill out your copyright notice in the Description page of Project Settings.


#include "Call.h"
#include "Components/BoxComponent.h"
#include "Train/TrainManager.h"
#include "Kismet/GameplayStatics.h"

ACall::ACall()
{
	CallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Call"));
	SetRootComponent(CallMesh);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(CallMesh);

}


void ACall::BeginPlay()
{

}

void ACall::Tick(float DeltaTime)
{
}

void ACall::OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	for (auto Gimmick : Gimmicks)
	{
		if (!Gimmick->GetIsGimmickCleared())
		{
			return;
		}
	}
	if (ClearSound)
		UGameplayStatics::PlaySoundAtLocation(this, ClearSound, GetActorLocation());
	TrainManager->ClearStage();
}