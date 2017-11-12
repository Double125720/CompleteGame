// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <vector>
#include "Engine.h"
#include <CPP_Item.h>
#include <CPP_Weapon.h>
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

	UPROPERTY(EditAnywhere, Category = "HP")
		int32 CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "HP")
		int32 MaxHealth;

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

	UPROPERTY(EditAnywhere)
		bool bIsUnderPlayerControl;

	UPROPERTY(EditAnywhere)
		bool bCanWalk;

	UPROPERTY(EditAnywhere)
		FVector CurrentPosition;

	UPROPERTY(EditAnywhere)
		TArray<ACPP_Item*> Inventory;

	UPROPERTY(EditAnywhere)
		TArray<ACPP_Item*> Equiped;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
