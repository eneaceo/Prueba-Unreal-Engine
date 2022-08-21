// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Spawner.h"
#include "PruebaGameMode.generated.h"

UCLASS(minimalapi)
class APruebaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APruebaGameMode();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (UIMin = "0.0"), Category = "SpawnOptions")
		float SpawnRate = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (UIMin = "0.0"), Category = "SpawnOptions")
		int MaxNumberOfEnemies = 5;

	UFUNCTION(BlueprintCallable)
		TArray < AActor* >& GetEnemyActorsRef() { return EnemyActors; };

	UFUNCTION(BlueprintCallable)
		void AddEnemyActor(AActor* Enemy);

	UFUNCTION(BlueprintCallable)
		void RemoveEnemyActor(AActor* Enemy);

	UFUNCTION(BlueprintCallable)
		bool IsEmptyEnemyActors();

	UFUNCTION(BlueprintCallable)
		int NumOfEnemyActors();

	UFUNCTION(BlueprintCallable)
		void AddEnemySpawner(ASpawner* Enemy);

	UFUNCTION(BlueprintCallable)
		void SpawnEnemy();

private:

	//Array for faster finding and counting of enemy actors
	UPROPERTY()
		TArray < AActor* > EnemyActors;

	//Array for spawners actors
	UPROPERTY()
		TArray < ASpawner* > Spawners;

	bool bFirstSpawner = true;
};



