// Fill out your copyright notice in the Description page of Project Settings.


#include "EmergencyBell.h"
#include "Components/AudioComponent.h"

// Sets default values
AEmergencyBell::AEmergencyBell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BellMesh"));
	RootComponent = BellMesh;

	NormalAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("NormalAudioComponent"));
	NormalAudioComponent->SetupAttachment(RootComponent);
	NormalAudioComponent->bAutoActivate = false;

	AbnormalAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AbnormalAudioComponent"));
	AbnormalAudioComponent->SetupAttachment(RootComponent);
	AbnormalAudioComponent->bAutoActivate = false;

	BellMesh->SetCustomDepthStencilValue(2);

}

// Called when the game starts or when spawned
void AEmergencyBell::BeginPlay()
{
	Super::BeginPlay();
	
	if (BellMesh)
	{
		BellMesh->OnClicked.AddDynamic(this, &AEmergencyBell::OnClickedGimmick);
	}
}

// Called every frame
void AEmergencyBell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEmergencyBell::Interact_Implementation()
{

	if (!NormalBellSound || !AbnormalBellSound)
	{
		UE_LOG(LogTemp, Warning, TEXT("EmergencyBell: Normal or AbNormal sound not set!"));
	}

	bool bNormalSoundPlayed = FMath::FRand() <= NormalBellRatio;

	if (bNormalSoundPlayed)
	{
		UE_LOG(LogTemp, Log, TEXT("Normal sound played."));
		NormalAudioComponent->SetSound(NormalBellSound);
		AbnormalAudioComponent->SetSound(nullptr);
		NormalAudioComponent->Play();
		AbnormalAudioComponent->Stop();

		NormalAudioComponent->FadeOut(3.0f, 0.0f);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Abnormal sound played."));
		NormalAudioComponent->SetSound(NormalBellSound);
		AbnormalAudioComponent->SetSound(AbnormalBellSound);
		NormalAudioComponent->Play();
		AbnormalAudioComponent->Play();

		NormalAudioComponent->FadeOut(3.0f, 0.0f);
		AbnormalAudioComponent->FadeOut(3.0f, 0.0f);
	}
	SetIsGimmickCleared(true);
}

void AEmergencyBell::OnBeginFocus_Implementation()
{
	if (BellMesh)
	{
		BellMesh->SetRenderCustomDepth(true); // 하이라이트 켜기
	}
}

void AEmergencyBell::OnEndFocus_Implementation()
{
	if (BellMesh)
	{
		BellMesh->SetRenderCustomDepth(false); // 하이라이트 끄기
	}
}

void AEmergencyBell::OnClickedGimmick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	Super::OnClickedGimmick(ClickedComp, ButtonPressed);

	if (!NormalBellSound || !AbnormalBellSound)
	{
		UE_LOG(LogTemp, Warning, TEXT("EmergencyBell: Normal or AbNormal sound not set!"));
	}

	bool bNormalSoundPlayed = FMath::FRand() <= NormalBellRatio;

	if (bNormalSoundPlayed)
	{
		UE_LOG(LogTemp, Log, TEXT("Normal sound played."));
		NormalAudioComponent->SetSound(NormalBellSound);
		AbnormalAudioComponent->SetSound(nullptr);
		NormalAudioComponent->Play();
		AbnormalAudioComponent->Stop();

		NormalAudioComponent->FadeOut(3.0f, 0.0f);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Abnormal sound played."));
		NormalAudioComponent->SetSound(NormalBellSound);
		AbnormalAudioComponent->SetSound(AbnormalBellSound);
		NormalAudioComponent->Play();
		AbnormalAudioComponent->Play();

		NormalAudioComponent->FadeOut(3.0f, 0.0f);
		AbnormalAudioComponent->FadeOut(3.0f, 0.0f);
	}

}

