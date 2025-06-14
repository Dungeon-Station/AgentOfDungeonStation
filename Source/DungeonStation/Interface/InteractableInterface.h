// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, Blueprintable,MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DUNGEONSTATION_API IInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// 마우스를 올릴 때 (외곽선 표시 등)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void OnBeginFocus();

	// 마우스를 내릴 때 (외곽선 제거 등)	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void OnEndFocus();

	// 상호작용 안내 텍스트 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	FText GetInteractionText();

	// 실제 상호작용 실행
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();

};
