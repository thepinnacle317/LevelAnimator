// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/ActorMovementData.h"

FLevelActorData UActorMovementData::GetLevelActorData()
{
	for (auto levelActor : LevelActorInfo)
	{
		return levelActor;
	}
	return {};
}
