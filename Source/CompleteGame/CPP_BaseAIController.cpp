// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_BaseAIController.h"

ACPP_BaseAIController::ACPP_BaseAIController()
{

}

bool ACPP_BaseAIController::Vision()
{
	TArray<AActor*> creatures = creatureManager->GetCreatureList();
	for (int i = 0; i < creatures.Num() - 1; i++)
	{
		if ((Cast<ACPP_Creature>(creatures[i])->bIsUnderPlayerControl) && (Cast<ACPP_Creature>(creatures[i])->Team == 0))
		{
			FVector vectToTarget = (this->GetPawn()->GetActorLocation() - creatures[i]->GetActorLocation());
			if (FVector::Dist(this->GetPawn()->GetActorLocation(), vectToTarget) <= Cast<ACPP_Creature>(this->GetPawn())->VisionDistance)
			{
				FVector normalDirVect = vectToTarget;
				normalDirVect.Normalize();
				FVector normalForward = this->GetPawn()->GetActorForwardVector();
				normalForward.Normalize();
				float angleBetween = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(normalDirVect, normalForward)));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Distance between creatures: %f"), FVector::DistXY(this->GetPawn()->GetActorLocation(), vectToTarget)));
				if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(normalDirVect, normalForward))) <= Cast<ACPP_Creature>(this->GetPawn())->FOV)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("I see creature #%i"), i));

					return true;
				}
			}
		}
	}
	return false;
}

void ACPP_BaseAIController::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_CreatureManager::StaticClass(), creatureManagerTmpArr);
	this->creatureManager = Cast<ACPP_CreatureManager>(creatureManagerTmpArr[0]);
}

void ACPP_BaseAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Vision();
}
