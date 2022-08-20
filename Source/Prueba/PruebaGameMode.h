// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PruebaGameMode.generated.h"

UCLASS(minimalapi)
class APruebaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APruebaGameMode();

	//
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

private:

	//Array for faster finding and counting of enemy actors
	UPROPERTY()
		TArray < AActor* > EnemyActors;
};



