
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.h"
#include "Enemy.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UWidgetComponent;

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

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
		UWidgetComponent* HealthWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component")
		float HealthWidgetRotationRate = 0.1f;

	UFUNCTION()
		void ReceiveDamage(float Damage);

	UFUNCTION(BlueprintCallable)
		void MoveAround(float DeltaTime);

protected:

	virtual void BeginPlay() override;

private:

	void RotateHealthBar();

};
