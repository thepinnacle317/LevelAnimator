// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ActorMovementData.generated.h"

/* Forward Declarations */
class ASplineActor;

USTRUCT(Blueprintable)
struct FLevelActorData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	AActor* LevelActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	ASplineActor* TargetMovementSpline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	float MovementSpeed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	float StopPercentage = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	bool bUseLookAtRotation = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	bool bUseXOffset = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	bool bUseYOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor | Properties")
	bool bUseZOffset;	
};

UCLASS()
class SPLINEMOVEMENT_API UActorMovementData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level Actor | Data")
	TArray<FLevelActorData> LevelActorInfo;

	FLevelActorData GetLevelActorData();
};
