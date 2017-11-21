// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_Creature.h"
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

	virtual void BeginPlay() override;
	
};
