
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBA_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UHealthComponent();

	UFUNCTION(BlueprintCallable)
		float GetHealth();

	UFUNCTION(BlueprintCallable)
		void SetHealth(float NewHealth);

	UFUNCTION(BlueprintCallable)
		float GetMaxHealth();

	UFUNCTION(BlueprintCallable)
		void SetMaxHealth(float NewMaxHealth);

	UFUNCTION(BlueprintCallable)
		void TakeDamage(float Damage);

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
		float MaxHealth = 100.0f;

private:

	float Health;

};
