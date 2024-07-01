// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SplineActor.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/LevelManager.h"

ASplineActor::ASplineActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline Component");

	FoundManager = UGameplayStatics::GetActorOfClass(this,ALevelManager::StaticClass());

	LevelManager = Cast<ALevelManager>(FoundManager);
}
