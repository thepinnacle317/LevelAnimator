// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SplineMovementComp.h"
#include "Actors/SplineActor.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
USplineMovementComp::USplineMovementComp()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USplineMovementComp::BeginPlay()
{
	Super::BeginPlay();

	// Find the closest spline actor from the root component of the actor that owns this component.
	if (bFindClosestSpline )
	{
		float Distance;
		// TODO: For testing.  Eventually this will be retrieved from the level manager data asset.
		UGameplayStatics::GetAllActorsOfClass(this, MovementSplineActor, OutSplineActors);
		TargetMovementSpline = Cast<ASplineActor>(UGameplayStatics::FindNearestActor(GetForwardLocation(), OutSplineActors, Distance));
	}
}

FVector USplineMovementComp::GetAxisLocation() const
{
	FVector OwnerLocation = TargetActor->GetActorLocation();
	FVector OwnerForwardVector = TargetActor->GetActorForwardVector();
	FVector OwnerUpVector = TargetActor->GetActorUpVector();
	FVector OwnerRightVector = TargetActor->GetActorRightVector();
	
	OwnerUpVector *= ForwardDistance;
	OwnerRightVector *= ForwardDistance;
	OwnerForwardVector *= ForwardDistance;
	if (bUseYOffset == true)
	{
		return OwnerLocation + OwnerRightVector;
	}
	else if (bUseZOffset == true)
	{
		return  OwnerLocation + OwnerUpVector;
	}
	else
	{
		return OwnerLocation + OwnerForwardVector;
	}
}

void USplineMovementComp::UpdateActorLocation()
{
	ActorMoveDestination = TargetMovementSpline->SplineComponent->FindLocationClosestToWorldLocation(GetAxisLocation(), ESplineCoordinateSpace::World);
}

void USplineMovementComp::MoveActorAlongSpline(float DeltaTime)
{
	LastUpdateTime = DeltaTime;

	float DeltaLocation = (Speed * MaxSpeed) * LastUpdateTime;
	if (bUseXOffset == true)
	{
		FVector Offset(DeltaLocation, 0.f, 0.f);
		LocalOffset = Offset;
	}
	else if (bUseYOffset == true)
	{
		FVector Offset(0.f, DeltaLocation, 0.f);
		LocalOffset = Offset;
	}
	else if (bUseZOffset == true)
	{
		FVector Offset(0.f, 0.f, DeltaLocation);
		LocalOffset = Offset;
	}
	else
	{
		// Always Default to use the X Offset to prevent any errors
		bUseXOffset = true;
		FVector Offset(DeltaLocation, 0.f, 0.f);
		LocalOffset = Offset;
	}
	
	if (PercentageTraveled != StopPercentage)
	{
		TargetActor->AddActorLocalOffset(LocalOffset);
		
		/* Optional Location */
		//FVector RootLocation = TargetActor->GetRootComponent()->GetComponentLocation();
		
		FVector RootLocation = TargetActor->GetActorLocation();
		FRotator RootRotation = TargetMovementSpline->SplineComponent->GetRelativeRotation();
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(RootLocation, ActorMoveDestination);
		
		/* Optional Rotation */
		//TargetActor->GetRootComponent()->SetWorldRotation(RootRotation);
		
		if (bUseLookAtRotation == false)
		{
			TargetActor->SetActorRotation(RootRotation);
		}
		else
		{
			TargetActor->SetActorRotation(LookAtRotation);
		}
	}
}

float USplineMovementComp::GetTraveledDistance()
{
	// Get the closest input key to the actor moving
	float ReturnValue = TargetMovementSpline->SplineComponent->FindInputKeyClosestToWorldLocation(GetOwner()->GetActorLocation());
	
	// Get the distance along the spline with the given input key
	DistanceAlongSpline = TargetMovementSpline->SplineComponent->GetDistanceAlongSplineAtSplineInputKey(ReturnValue);
	
	// Get the spline length
	float SplineLength = TargetMovementSpline->SplineComponent->GetSplineLength();
	
	// The percentage will be used to set a stop distance for the actor along the spline
	PercentageTraveled = (DistanceAlongSpline / SplineLength) * 100.f;
	return PercentageTraveled;
}

FVector USplineMovementComp::GetForwardLocation()
{
	FVector OwnerLocation = GetOwner()->GetActorLocation();
	FVector ForwardVector = GetOwner()->GetActorForwardVector();
	FVector ForwardLook = ForwardVector * ForwardDistance;
	return OwnerLocation + ForwardLook;
}
