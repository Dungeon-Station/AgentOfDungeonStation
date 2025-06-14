// Fill out your copyright notice in the Description page of Project Settings.


#include "../Item/ItemPhone.h"

AItemPhone::AItemPhone()
{
	InteractionText = FText::FromString(TEXT("전화기를 줍는다"));
}

void AItemPhone::Interact_Implementation()
{
	Super::Interact_Implementation();

	SetIsGimmickCleared(true);
	UE_LOG(LogTemp, Warning, TEXT("ItemPhone과 상호작용했습니다. 액터를 파괴합니다."));
	Destroy();
}
