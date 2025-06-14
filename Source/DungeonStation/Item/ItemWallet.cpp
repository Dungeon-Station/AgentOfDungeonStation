// Fill out your copyright notice in the Description page of Project Settings.


#include "../Item/ItemWallet.h"

AItemWallet::AItemWallet()
{
	InteractionText = FText::FromString(TEXT("지갑을 줍는다"));
}

void AItemWallet::Interact_Implementation()
{
	Super::Interact_Implementation();

	SetIsGimmickCleared(true);
	UE_LOG(LogTemp, Warning, TEXT("ItemWallet과 상호작용했습니다."));
	SetActorHiddenInGame(true);
}
