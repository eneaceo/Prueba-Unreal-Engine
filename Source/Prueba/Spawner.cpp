
#include "Spawner.h"
#include "PruebaGameMode.h"

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetAuthGameMode<APruebaGameMode>()->AddEnemySpawner(this);
}

void ASpawner::SpawnEnemy()
{
	if (!EnemyClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Enemy class not selected ... "), *GetName());
		return;
	}

	// Get spawn transform
	FTransform Transform;
	Transform.SetLocation(GetActorLocation());
	Transform.SetRotation(GetActorRotation().Quaternion());

	// Spawn Enemy
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AEnemy>(EnemyClass, Transform, SpawnParams);
}

