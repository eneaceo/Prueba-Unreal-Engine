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

void APruebaGameMode::SpawnEnemy()
{
	if (EnemyActors.Num() < MaxNumberOfEnemies && Spawners.Num() > 0)
	{
		//Random spawn point
		Spawners[FMath::RandRange(0, Spawners.Num()-1)]->SpawnEnemy();
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

void APruebaGameMode::AddEnemySpawner(ASpawner* Spawner)
{
	Spawners.Add(Spawner);

	if (bFirstSpawner)
	{
		bFirstSpawner = false;

		//If there is no spawners we can't spawn enemies, we wait for the first one to start spawning enemies
		FTimerHandle TimerHandle;
		bool bLooping = true;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APruebaGameMode::SpawnEnemy, SpawnRate, bLooping);

	}
}


