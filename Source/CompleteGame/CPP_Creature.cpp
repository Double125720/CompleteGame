// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Creature.h"


// Sets default values
ACPP_Creature::ACPP_Creature()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentHealth = HeadHP + ChestHP + LeftHandHP + RightHandHP + TorsoHP + LeftLegHP + RightLegHP;
	MaxHealth = CurrentHealth;
	MaxHeadHP = HeadHP;
	MaxChestHP = ChestHP;
	MaxLeftHandHP = LeftHandHP;
	MaxRightHandHP = RightHandHP;
	MaxTorsoHP = TorsoHP;
	MaxLeftLegHP = LeftLegHP;
	MaxRightLegHP = RightLegHP;
}

void ACPP_Creature::SetTeam(int TeamToSet)
{
	this->Team = TeamToSet;
}

void ACPP_Creature::Death()
{
	bIsDead = true;
}

void ACPP_Creature::DealDamage(ACPP_Creature * Target, int Part, int Damage, int TypeOfDamage)
{
	switch (Part)
	{
	case 0:
		Target->HeadHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[0])->ArmorLevel;
		ChangeHP();
		break;
	case 1:
		Target->ChestHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[1])->ArmorLevel;
		ChangeHP();
		break;
	case 2:
		Target->LeftHandHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[2])->ArmorLevel;
		ChangeHP();
		break;
	case 3:
		Target->RightHandHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[3])->ArmorLevel;
		ChangeHP();
		break;
	case 4:
		Target->TorsoHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[1])->ArmorLevel;
		ChangeHP();
		break;
	case 5:
		Target->LeftLegHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[5])->ArmorLevel;
		ChangeHP();
		break;
	case 6:
		Target->RightLegHP -= Damage - Cast<ACPP_Armor, ACPP_Item>(Target->Equipped[6])->ArmorLevel;
		ChangeHP();
		break;
	default:
		break;
	}
}

void ACPP_Creature::ChangeHP()
{
	CurrentHealth = HeadHP + ChestHP + LeftHandHP + RightHandHP + TorsoHP + LeftLegHP + RightLegHP;
}

// Called when the game starts or when spawned
void ACPP_Creature::BeginPlay()
{
	Super::BeginPlay();
	bIsDead = false;
}

// Called every frame
void ACPP_Creature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ChangeHP();
}

// Called to bind functionality to input
void ACPP_Creature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

