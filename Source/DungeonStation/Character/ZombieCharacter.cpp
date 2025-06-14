// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCharacter.h"

// Sets default values
AZombieCharacter::AZombieCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCustomDepthStencilValue(2);
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AZombieCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombieCharacter::TriggerZombieAnimation()
{
}

void AZombieCharacter::OnBeginFocus_Implementation()
{
	if (GetMesh())
	{
		GetMesh()->SetRenderCustomDepth(true); // 하이라이트 켜기
	}
}

void AZombieCharacter::OnEndFocus_Implementation()
{
	if (GetMesh())
	{
		GetMesh()->SetRenderCustomDepth(false); // 하이라이트 끄기
	}
}

FText AZombieCharacter::GetInteractionText_Implementation()
{
	return FText();
}

void AZombieCharacter::Interact_Implementation()
{
}

