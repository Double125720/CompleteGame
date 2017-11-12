// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_CreatureManager.h"


// Sets default values
ACPP_CreatureManager::ACPP_CreatureManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACPP_CreatureManager::AddCreature(ACPP_Creature * character)
{
	this->CreatureList.Add(character);
}

TArray<ACPP_Creature*> ACPP_CreatureManager::GetCreatureList()
{
	return TArray<ACPP_Creature*>();
}

// Called when the game starts or when spawned
void ACPP_CreatureManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_CreatureManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

