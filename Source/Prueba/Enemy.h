
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.h"
#include "Enemy.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UWidgetComponent;
class UBoxComponent;

UCLASS()
class PRUEBA_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	

	AEnemy();

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* CollisionBox = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
		UHealthComponent* HealthComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Widget")
		UWidgetComponent* HealthWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widget")
		float HealthWidgetRotationRate = 0.1f;

	UFUNCTION()
		void ReceiveDamage(float Damage);

	//Function just for them not be on top of each other when they spawn
	UFUNCTION(BlueprintCallable)
		void MoveAround(float DeltaTime);

protected:

	virtual void BeginPlay() override;

private:

	void RotateHealthBar();

};
