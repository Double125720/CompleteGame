// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_BaseAIController.h"

ACPP_BaseAIController::ACPP_BaseAIController()
{

}

bool ACPP_BaseAIController::Vision()
{
	if (!Cast<ACPP_Creature>(this->GetPawn())->bIsUnderPlayerControl)
	{
		TArray<AActor*> creatures = creatureManager->GetCreatureList();
		for (int i = 0; i < creatures.Num() - 1; i++)
		{
			if ((Cast<ACPP_Creature>(creatures[i])->bIsUnderPlayerControl) && (Cast<ACPP_Creature>(creatures[i])->Team == 0))
			{
				DrawDebugLine(GetWorld(), this->GetPawn()->GetActorLocation(), (this->GetPawn()->GetActorLocation() + (this->GetPawn()->GetActorForwardVector()*250)), FColor::Red);
				DrawDebugLine(GetWorld(), this->GetPawn()->GetActorLocation(), creatures[i]->GetActorLocation(), FColor::Green);
				FVector vectToTarget = (creatures[i]->GetActorLocation() - this->GetPawn()->GetActorLocation());
				if (FVector::Dist(this->GetPawn()->GetActorLocation(), vectToTarget) <= Cast<ACPP_Creature>(this->GetPawn())->VisionDistance)
				{
					FVector normalDirVect = vectToTarget;
					normalDirVect.Normalize();
					float angleBetween = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(this->GetPawn()->GetActorForwardVector(), normalDirVect)));
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Angle between: %f"), angleBetween));
					if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(this->GetPawn()->GetActorForwardVector(), normalDirVect))) <= Cast<ACPP_Creature>(this->GetPawn())->FOV)
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("FOV is alright")));
						ECollisionChannel CollisionChannel = ECC_Visibility;
						FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), true, this->GetPawn());
						TraceParams.bTraceComplex = true;
						TraceParams.AddIgnoredActor(Cast<AActor>(this->GetPawn()));
						
						FHitResult HitOut(ForceInit);
						if (GetWorld()->LineTraceSingleByChannel(HitOut, this->GetPawn()->GetActorLocation(), creatures[i]->GetActorLocation(), CollisionChannel, TraceParams))
						{
							if (HitOut.GetActor() == creatures[i])
							{
								DrawDebugLine(GetWorld(), this->GetPawn()->GetActorLocation(), creatures[i]->GetActorLocation(), FColor::Blue, true);
								GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("I see the playah")));
								return true;
							}
						}

					}
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
