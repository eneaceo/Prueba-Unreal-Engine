
#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "CapsuleEnemy.generated.h"

class UCapsuleComponent;

/**
 * 
 */
UCLASS()
class PRUEBA_API ACapsuleEnemy : public AEnemy
{
	GENERATED_BODY()

	ACapsuleEnemy();

	UPROPERTY(EditDefaultsOnly)
		UCapsuleComponent* CollisionCapsule = nullptr;
	
};
