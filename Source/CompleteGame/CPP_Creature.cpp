// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Creature.h"


// Sets default values
ACPP_Creature::ACPP_Creature()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACPP_Creature::SetTeam(int TeamToSet)
{
	this->Team = TeamToSet;
}

void ACPP_Creature::Death()
{
}

// Called when the game starts or when spawned
void ACPP_Creature::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_Creature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACPP_Creature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

