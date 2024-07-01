// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SplineMovementComp.generated.h"

/* Forward Declarations */
class ASplineActor;

UCLASS( ClassGroup=(SplineMovement), meta=(BlueprintSpawnableComponent), BlueprintType )
class SPLINEMOVEMENT_API USplineMovementComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	USplineMovementComp();
	
	/* Actor Properties */
	UPROPERTY(EditAnywhere, Category = "Spline Actor")
	TSubclassOf<ASplineActor> MovementSplineActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Properties")
	bool bFindClosestSpline = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties")
	bool bUseLookAtRotation = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties|Offset")
	bool bUseXOffset = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties|Offset")
	bool bUseYOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties|Offset")
	bool bUseZOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties|Speed")
	float Speed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties|Speed")
	float MaxSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties")
	float StopPercentage = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties")
	float ForwardDistance = 150.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Properties")
	ASplineActor* TargetMovementSpline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Properties|Actor")
	AActor* TargetActor;
	
	/* Do Not Edit */
	UPROPERTY()
	float LastUpdateTime = 0.f;
	
	UPROPERTY()
	float DistanceAlongSpline;

	UPROPERTY()
	float PercentageTraveled;

	UPROPERTY()
	FVector ActorMoveDestination;

	UPROPERTY()
	TArray<AActor*> OutSplineActors;

	UPROPERTY()
	FVector LocalOffset;

protected:
	virtual void BeginPlay() override;

	FVector GetAxisLocation() const;

	UFUNCTION(BlueprintCallable, Category = "Level Animator | Movement Functions")
	void UpdateActorLocation();

	UFUNCTION(BlueprintCallable, Category = "Level Animator | Movement Functions")
	void MoveActorAlongSpline(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Level Animator | Movement Functions")
	float GetTraveledDistance();

	UFUNCTION(BlueprintCallable, meta = (BlueprintPure) , Category = "Level Animator | Movement Functions")
	FVector GetForwardLocation();
};
