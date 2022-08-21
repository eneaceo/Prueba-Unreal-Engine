
#include "Spawner.h"
#include "PruebaGameMode.h"

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetAuthGameMode<APruebaGameMode>()->AddEnemySpawner(this);
}

void ASpawner::SpawnEnemy()
{
	if (ArrayEnemyClass.Num() == 0)
	{
		return;
	}

	// Get spawn transform
	FTransform Transform;
	Transform.SetLocation(GetActorLocation());
	Transform.SetRotation(GetActorRotation().Quaternion());

	// Spawn Enemy
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AEnemy>(ArrayEnemyClass[FMath::RandRange(0, ArrayEnemyClass.Num()-1)] , Transform, SpawnParams);
}

