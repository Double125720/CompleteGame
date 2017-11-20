// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_BattleManager.h"


// Sets default values
ACPP_BattleManager::ACPP_BattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	counter = 0;
}

void ACPP_BattleManager::SortByInitiative()
{

}

// Called when the game starts or when spawned
void ACPP_BattleManager::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_Creature::StaticClass(), CreatureList);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_BaseAIController::StaticClass(), AIControllerList);

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
		if (!Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnStart)
		{
			Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnStart = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Start turn of: %f"), counter));
		}

		else
		{
			if (Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnEnd)
			{
				Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnStart = false;
				Cast<ACPP_Creature>(Cast<AAIController>(AIControllerList[counter])->GetPawn())->bIsTurnEnd = false;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("End turn of: %f"), counter));
				counter++;
				if (counter == AIControllerList.Num())
				{
					counter = 0;
				}

				else
				{
					counter++;
				}
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

