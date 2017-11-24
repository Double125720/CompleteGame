// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_Item.h"
#include "CPP_Container.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPLETEGAME_API UCPP_Container : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_Container();

	UPROPERTY(EditAnywhere, SaveGame)
		TArray<ACPP_Item*> content;

	UPROPERTY(EditAnywhere, SaveGame)
		bool bIsRandomLootAtSpawn;

	UFUNCTION(BlueprintCallable)
		void RandomizeLoot();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
