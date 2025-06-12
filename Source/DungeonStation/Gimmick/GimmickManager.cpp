// Fill out your copyright notice in the Description page of Project Settings.


#include "GimmickManager.h"

// Sets default values
AGimmickManager::AGimmickManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGimmickManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGimmickManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

