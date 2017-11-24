// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Container.h"


// Sets default values for this component's properties
UCPP_Container::UCPP_Container()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UCPP_Container::RandomizeLoot()
{
	//TODO: Randomize loot
}

// Called when the game starts
void UCPP_Container::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UCPP_Container::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

