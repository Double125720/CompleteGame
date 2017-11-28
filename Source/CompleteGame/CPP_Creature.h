// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <vector>
#include "Engine.h"
#include <CPP_Item.h>
#include <CPP_Weapon.h>
#include <CPP_Armor.h>
#include <AIController.h>
#include "CPP_Creature.generated.h"

UCLASS()
class COMPLETEGAME_API ACPP_Creature : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPP_Creature();

	UPROPERTY(EditAnywhere)
		FString Name;

	UPROPERTY(EditAnywhere, Category = "HP|SummaryHP")
		uint32 CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "HP|SummaryHP")
		uint32 MaxHealth;

	UPROPERTY(EditAnywhere, Category = "HP|HeadHP")
		uint32 HeadHP; // 0

	UPROPERTY(EditAnywhere, Category = "HP|HeadHP")
		uint32 MaxHeadHP;

	UPROPERTY(EditAnywhere, Category = "HP|ChestHP")
		uint32 ChestHP; // 1

	UPROPERTY(EditAnywhere, Category = "HP|ChestHP")
		uint32 MaxChestHP;

	UPROPERTY(EditAnywhere, Category = "HP|LeftHandHP")
		uint32 LeftHandHP; // 2

	UPROPERTY(EditAnywhere, Category = "HP|LeftHandHP")
		uint32 MaxLeftHandHP;

	UPROPERTY(EditAnywhere, Category = "HP|RightHandHP")
		uint32 RightHandHP; // 3

	UPROPERTY(EditAnywhere, Category = "HP|RightHandHP")
		uint32 MaxRightHandHP;

	UPROPERTY(EditAnywhere, Category = "HP|TorsoHP")
		uint32 TorsoHP; // 4

	UPROPERTY(EditAnywhere, Category = "HP|TorsoHP")
		uint32 MaxTorsoHP;

	UPROPERTY(EditAnywhere, Category = "HP|LeftLegHP")
		uint32 LeftLegHP; // 5

	UPROPERTY(EditAnywhere, Category = "HP|LeftLegHP")
		uint32 MaxLeftLegHP;

	UPROPERTY(EditAnywhere, Category = "HP|RightLegHP")
		uint32 RightLegHP; // 6

	UPROPERTY(EditAnywhere, Category = "HP|RightLegHP")
		uint32 MaxRightLegHP;

	UPROPERTY(EditAnywhere, Category = "AP")
		uint32 CurrentAP;

	UPROPERTY(EditAnywhere, Category = "AP")
		uint32 MaxAP;

	UPROPERTY(EditAnywhere, Category = "Characteristics")
		uint32 Initiative;

	UPROPERTY(EditAnywhere, Category = "Characteristics")
		uint32 Strength;

	UPROPERTY(EditAnywhere, Category = "Characteristics")
		uint32 Agility;

	UPROPERTY(EditAnywhere, Category = "Characteristics")
		uint32 Endurance;

	UPROPERTY(EditAnywhere, Category = "Characteristics")
		uint32 Intelligence;

	UPROPERTY(EditAnywhere, Category = "Characteristics")
		uint32 Accuracy;

	UPROPERTY(EditAnywhere, Category = "Characteristircs|Vision")
		float VisionDistance;
	
	UPROPERTY(EditAnywhere, Category = "Characteristircs|Vision")
		float FOV;

	UPROPERTY(EditAnywhere)
		bool bIsUnderPlayerControl;

	UPROPERTY(EditAnywhere)
		bool bCanWalk;

	UPROPERTY(EditAnywhere)
		FVector CurrentPosition;

	UPROPERTY(EditAnywhere)
		TArray<ACPP_Item*> Inventory;

	UPROPERTY(EditAnywhere)
		TArray<ACPP_Item*> Equipped;

	UPROPERTY(EditAnywhere)
		uint32 Team;

	UPROPERTY(EditAnywhere)
		bool bIsDead;

	UFUNCTION(BlueprintCallable)
		void SetTeam(int TeamToSet);

	UFUNCTION(BlueprintCallable)
		void Death();

	UFUNCTION(BlueprintCallable)
		void DealDamage(ACPP_Creature* Target, int Part = 0, int Damage = 1, int TypeOfDamage = 0);

	UPROPERTY(EditAnywhere)
		bool bIsTurnStart;

	UPROPERTY(EditAnywhere)
		bool bIsTurnEnd;

	UFUNCTION(BlueprintCallable)
		bool getEndTurnState();

	UFUNCTION(BlueprintCallable)
		void setEndTurnState(bool turnState);

	UFUNCTION(BlueprintCallable)
		bool getStartTurnState();

	UFUNCTION(BlueprintCallable)
		void setStartTurnState(bool turnState);

	UFUNCTION(BlueprintCallable)
		bool getIsControlledByPlayer();

	UFUNCTION(BlueprintCallable)
		void setIsControlledByPlayer(bool state);

	UPROPERTY(EditAnywhere)
		AAIController* CreatureAI;

	UFUNCTION(BlueprintCallable)
		void setCreatureAI(AAIController* AIController);

	UFUNCTION(BlueprintCallable)
		AAIController* getCreatureAI();

	void ChangeHP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
