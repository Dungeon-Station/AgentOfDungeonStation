// Fill out your copyright notice in the Description page of Project Settings.


#include "Graffiti.h"
#include "Components/DecalComponent.h"
#include "Components/BoxComponent.h"

AGraffiti::AGraffiti()
{
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Plane"));
	RootComponent = Plane;

	GraffitiDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("GraffitiDecal"));
	GraffitiDecal->DecalSize = FVector(10, 20, 15);
	GraffitiDecal->SetupAttachment(Plane);

	GraffitiVolumeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("GraffitiVolumeBox"));
	GraffitiVolumeBox->SetupAttachment(RootComponent);
	GraffitiVolumeBox->SetBoxExtent(FVector(10, 20, 15));
	GraffitiVolumeBox->SetCollisionProfileName(TEXT("BlockAll"));
	GraffitiVolumeBox->bHiddenInGame = true;

	Plane->SetCustomDepthStencilValue(2);

}

void AGraffiti::BeginPlay()
{
	Super::BeginPlay();

	if (GraffitiVolumeBox)
	{
		GraffitiVolumeBox->OnClicked.AddDynamic(this, &AGraffiti::OnClickedGimmick);
	}

}

void AGraffiti::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGraffiti::OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	Super::OnClickedGimmick(ClickedComp, ButtonPressed);

	SetIsGimmickCleared(true);
	GraffitiDecal->SetFadeOut(0.0f, 1.0f);
}

void AGraffiti::Interact_Implementation()
{
	if (GetIsGimmickCleared())
		return;
	SetIsGimmickCleared(true);
	GraffitiDecal->SetFadeOut(0.0f, 1.0f);
}

void AGraffiti::OnBeginFocus_Implementation()
{
	if (Plane)
	{
		Plane->SetRenderCustomDepth(true); // 하이라이트 켜기
	}
}

void AGraffiti::OnEndFocus_Implementation()
{
	if (Plane)
	{
		Plane->SetRenderCustomDepth(false); // 하이라이트 끄기
	}
}
