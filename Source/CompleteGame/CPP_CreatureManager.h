// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Creature.h"
#include "CPP_CreatureManager.generated.h"

UCLASS()
class COMPLETEGAME_API ACPP_CreatureManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_CreatureManager();

	UFUNCTION(BlueprintCallable)
		void AddCreature(ACPP_Creature* character);

	UFUNCTION(BlueprintCallable)
		TArray<ACPP_Creature*> GetCreatureList();

	UPROPERTY(EditAnywhere)
		TArray<AActor*> CreatureList;

	UPROPERTY(EditAnywhere)
		FString Something;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
