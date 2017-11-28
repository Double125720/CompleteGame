// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_Creature.h"
#include "CPP_CreatureManager.h"
#include "CPP_BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class COMPLETEGAME_API ACPP_BaseAIController : public AAIController
{
	GENERATED_BODY()

public:

	ACPP_BaseAIController();
	
	UFUNCTION(BlueprintCallable)
		bool Vision();

	UPROPERTY(EditAnywhere)
		ACPP_CreatureManager* creatureManager;

	TArray<AActor*> creatureManagerTmpArr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
