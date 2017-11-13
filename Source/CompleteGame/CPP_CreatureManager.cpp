// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_CreatureManager.h"


// Sets default values
ACPP_CreatureManager::ACPP_CreatureManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACPP_CreatureManager::AddCreature(AActor* creature)
{
	this->CreatureList.Add(creature);
}

TArray<AActor*> ACPP_CreatureManager::GetCreatureList()
{
	return CreatureList;
}

void ACPP_CreatureManager::SpawnCreature(int creatureType = 0, int level = 0, int team = 0, FVector location = FVector(0.0f, 0.0f, 0.0f))
{
	if (creatureType == 0)
	{
		FRotator rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		AddCreature(GetWorld()->SpawnActor<ACPP_Creature>(location, rotation, SpawnInfo));
		Cast<ACPP_Creature, AActor>(CreatureList.Last())->SetTeam(team);
	}
}

// Called when the game starts or when spawned
void ACPP_CreatureManager::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_Creature::StaticClass(), CreatureList);
}

// Called every frame
void ACPP_CreatureManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

