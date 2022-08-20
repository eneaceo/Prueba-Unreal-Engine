
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.h"
#include "Enemy.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class PRUEBA_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	

	AEnemy();

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
		UHealthComponent* HealthComponent;
	
	UFUNCTION()
		void ReceiveDamage(float Damage);

protected:

	virtual void BeginPlay() override;

};
