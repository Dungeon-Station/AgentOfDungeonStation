// Fill out your copyright notice in the Description page of Project Settings.


#include "Graffiti.h"
#include "Components/DecalComponent.h"
#include "Components/BoxComponent.h"

AGraffiti::AGraffiti()
{
	GraffitiDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("GraffitiDecal"));
	RootComponent = GraffitiDecal;
	GraffitiDecal->DecalSize = FVector(10, 20, 15);

	GraffitiVolumeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("GraffitiVolumeBox"));
	GraffitiVolumeBox->SetupAttachment(RootComponent);
	GraffitiVolumeBox->SetBoxExtent(FVector(10, 20, 15));
	GraffitiVolumeBox->SetCollisionProfileName(TEXT("BlockAll"));
	GraffitiVolumeBox->bHiddenInGame = true;

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
