// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Item.h"
#include "CPP_Armor.generated.h"

/**
 * 
 */
UCLASS()
class COMPLETEGAME_API ACPP_Armor : public ACPP_Item
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
		uint8 Slot;
	
	
	
};
