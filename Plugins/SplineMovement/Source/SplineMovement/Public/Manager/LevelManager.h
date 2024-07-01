// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelManager.generated.h"

/* Forward Declarations */
class UActorMovementData;
class USplineMovementComp;
struct FLevelActorData;

UCLASS()
class SPLINEMOVEMENT_API ALevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelManager();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level Actor Data Asset")
	TObjectPtr<UActorMovementData> LevelActorData;

	// Set per instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Actor Data Asset")
	TArray<FLevelActorData> ActorsData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spline Component")
	TObjectPtr<USplineMovementComp> ActorMovement;

protected:
	virtual void BeginPlay() override;

};
