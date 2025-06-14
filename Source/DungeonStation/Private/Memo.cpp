// Fill out your copyright notice in the Description page of Project Settings.


#include "Memo.h"

// Sets default values
AMemo::AMemo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Memo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Memo"));
	SetRootComponent(Memo);

	Memo->SetCustomDepthStencilValue(2);
}

// Called when the game starts or when spawned
void AMemo::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AMemo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMemo::Interact_Implementation()
{
}

void AMemo::OnBeginFocus_Implementation()
{
	if (Memo)
	{
		Memo->SetRenderCustomDepth(true); // 하이라이트 켜기
	}
}

void AMemo::OnEndFocus_Implementation()
{
	if (Memo)
	{
		Memo->SetRenderCustomDepth(false); // 하이라이트 끄기
	}
}

