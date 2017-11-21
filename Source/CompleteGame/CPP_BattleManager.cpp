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

void ACPP_BattleManager::SortByInitiative()
{

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

	//Cast<AAIController>(AIControllerList[0])->GetBlackboardComponent()->SetValueAsBool("isWait", true);
}

int ACPP_BattleManager::getCounter()
{
	return counter;
}

void ACPP_BattleManager::setCounter(int newCounter)
{
	this->counter = newCounter;
}

// Called every frame
void ACPP_BattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsUnderPlayerControl)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Selected %i"), counter));
		if (!Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnStart)
		{
			Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnStart = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Start turn of: %i"), counter));
		}

		else
		{
			if (Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnEnd)
			{
				Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnStart = false;
				Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnEnd = false;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("End turn of: %i"), counter));
				counter++;
				if (counter == AIControllerList.Num()) { counter = 0; }
			}
		}
	}
	else
	{
		if (Cast<AAIController>(AIControllerList[counter])->GetBlackboardComponent()->GetValueAsBool("isWait"))
		{
			//DO NOTHING;
		}

		else
		{
			if (!Cast<AAIController>(AIControllerList[counter])->GetBlackboardComponent()->GetValueAsBool("isWait"))
			{
				Cast<AAIController>(AIControllerList[counter])->GetBlackboardComponent()->SetValueAsBool("isWait", true);
			}
			counter++;
		}

		if (counter == AIControllerList.Num())
		{
			counter = 0;
		}
	}
}

