// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_BattleManager.h"


// Sets default values
ACPP_BattleManager::ACPP_BattleManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

TArray<AActor*> ACPP_BattleManager::getAIControllerList()
{
	return AIControllerList;
}

TArray<ACPP_Creature*> ACPP_BattleManager::getCreatureList()
{
	return CreatureList;
}

void ACPP_BattleManager::AddToCreatureList(ACPP_Creature * Creature)
{
	CreatureList.Add(Creature);
}

ACPP_Creature * ACPP_BattleManager::getCurrentTurnCreature()
{
	return CreatureList[counter];
}

void ACPP_BattleManager::SortByInitiative()
{
	ACPP_Creature* temp;
	for (int i = 0; i < CreatureList.Num() - 1; i++)
	{
		for (int j = 0; j < CreatureList.Num() - i - 1; j++)
		{
			if (CreatureList[j]->Initiative > CreatureList[j + 1]->Initiative)
			{
				temp = CreatureList[j];
				CreatureList[j] = CreatureList[j + 1];
				CreatureList[j + 1] = temp;
			}
			else if ((CreatureList[j]->Initiative == CreatureList[j + 1]->Initiative) && CreatureList[j]->bIsUnderPlayerControl) {}
		}
	}

	Algo::Reverse(CreatureList);
}

// Called when the game starts or when spawned
void ACPP_BattleManager::BeginPlay()
{
	Super::BeginPlay();
	counter = 0;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_BaseAIController::StaticClass(), AIControllerList);
	for (int i = AIControllerList.Num() - 1; i >= 0; i--)
	{
		CreatureList.Add(Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[i])->GetPawn()));
	}

	SortByInitiative();
}

int ACPP_BattleManager::getCounter()
{
	return counter;
}

void ACPP_BattleManager::setCounter(int newCounter)
{
	this->counter = newCounter;
}

void ACPP_BattleManager::CheckDead()
{
	for (int i = 0; i < CreatureList.Num() - 1; i++)
	{
		if (CreatureList[i]->bIsDead)
		{
			CreatureList.RemoveAt(i);
		}
	}
}

// Called every frame
void ACPP_BattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CreatureList.Num() > 1)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Selected %i"), counter));
		if (!CreatureList[counter]->bIsTurnStart && !CreatureList[counter]->bIsDead)
		{
			CreatureList[counter]->bIsTurnStart = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Start turn of: %i"), counter));
		}

		else if (CreatureList[counter]->bIsDead)
		{
			CreatureList[counter]->bIsTurnStart = false;
			CreatureList[counter]->bIsTurnEnd = false;
			CreatureList.RemoveAt(counter);
			counter++;
			if (counter == CreatureList.Num()) { counter = 0; }
		}

		else
		{
			if (CreatureList[counter]->bIsTurnEnd)
			{
				CreatureList[counter]->bIsTurnStart = false;
				CreatureList[counter]->bIsTurnEnd = false;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("End turn of: %i"), counter));
				counter++;
				if (counter == CreatureList.Num()) { counter = 0; }
			}
		}
		if (CreatureList.Num() > 1)
		{
			SortByInitiative();
		}
	}
	if (CreatureList.Num() == 1)
	{
		CheckDead();
	}
}

