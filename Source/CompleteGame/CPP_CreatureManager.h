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
		void AddCreature(AActor* creature);

	UFUNCTION(BlueprintCallable)
		TArray<AActor*> GetCreatureList();

	UFUNCTION(BlueprintCallable)
		void SpawnCreature(int creatureType, int level, FVector location);

	UPROPERTY(EditAnywhere)
		TArray<AActor*> CreatureList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
