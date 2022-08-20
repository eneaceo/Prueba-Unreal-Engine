
#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "BoxEnemy.generated.h"


class UBoxComponent;

/**
 * 
 */
UCLASS()
class PRUEBA_API ABoxEnemy : public AEnemy
{
	GENERATED_BODY()

	ABoxEnemy();

	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* CollisionBox = nullptr;
	
};
