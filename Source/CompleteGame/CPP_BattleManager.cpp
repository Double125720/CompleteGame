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

	Cast<AAIController>(AIControllerList[0])->GetBlackboardComponent()->SetValueAsBool("isWait", true);
}

// Called every frame
void ACPP_BattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Cast<AAIController>(AIControllerList[counter])->GetBlackboardComponent()->GetValueAsBool("isWait"))
	{
		//DO NOTHING;
	}

	else
	{
		counter++;
	}

	if (counter == AIControllerList.Num())
	{
		counter = 0;
	}
}

