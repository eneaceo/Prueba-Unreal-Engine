// Copyright Epic Games, Inc. All Rights Reserved.

#include "PruebaGameMode.h"
#include "PruebaCharacter.h"
#include "UObject/ConstructorHelpers.h"

APruebaGameMode::APruebaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APruebaGameMode::AddEnemyActor(AActor* Enemy)
{
	EnemyActors.Add(Enemy);
}

void APruebaGameMode::RemoveEnemyActor(AActor* Enemy)
{
	EnemyActors.Remove(Enemy);
}

bool APruebaGameMode::IsEmptyEnemyActors()
{
	return EnemyActors.Num() == 0;
}

int APruebaGameMode::NumOfEnemyActors()
{
	return EnemyActors.Num();
}