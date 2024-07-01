// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/LevelManager.h"
#include "Data/ActorMovementData.h"

ALevelManager::ALevelManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALevelManager::BeginPlay()
{
	Super::BeginPlay();

	// Set the data to the actor info in the DA
	LevelActorData->LevelActorInfo = ActorsData;
}

void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* Has Function called on Tick in Blueprints */
}

