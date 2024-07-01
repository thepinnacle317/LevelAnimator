// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplineActor.generated.h"

class ALevelManager;
/* Forward Declarations */
class USplineComponent;

UCLASS()
class SPLINEMOVEMENT_API ASplineActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASplineActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Component")
	TObjectPtr<USplineComponent> SplineComponent;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Manager")
	TObjectPtr<ALevelManager> LevelManager;

private:
	UPROPERTY()
	AActor* FoundManager;
};
