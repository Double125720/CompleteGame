// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Creature.h"
#include "AIController.h"
#include "CPP_BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Algo/Reverse.h"
#include "CPP_BattleManager.generated.h"

UCLASS()
class COMPLETEGAME_API ACPP_BattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_BattleManager();

	UPROPERTY(EditAnywhere)
		TArray<ACPP_Creature*> CreatureList;

	UPROPERTY(EditAnywhere)
		TArray<AActor*> AIControllerList;

	UPROPERTY(EditAnywhere)
		int counter;
	
	UFUNCTION(BlueprintCallable)
		int getCounter();

	UFUNCTION(BlueprintCallable)
		void setCounter(int newCounter);

	UFUNCTION(BlueprintCallable)
		TArray<AActor*> getAIControllerList();

	UFUNCTION(BlueprintCallable)
		TArray<ACPP_Creature*> getCreatureList();

	UFUNCTION(BlueprintCallable)
		void AddToCreatureList(ACPP_Creature* Creature);

	UFUNCTION(BlueprintCallable)
		void CheckDead();

	UFUNCTION(BlueprintCallable)
		ACPP_Creature* getCurrentTurnCreature();

	void SortByInitiative();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
