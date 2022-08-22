
#pragma once

#include "CoreMinimal.h"
#include "ProjectileSpawnerComponent.generated.h"

class AProjectile;
class ACharacter;

/*
	Actor Component for spawning projectiles
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBA_API UProjectileSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

protected:	

	//Projectile class to spawn
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectile> ProjectileClass;

	UFUNCTION(BlueprintCallable)
		void Fire();

	UFUNCTION(BlueprintCallable)
		void StopFire();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (UIMin = "0.0"), Category = "FireOptions")
		float FireRate = 0.2f;

	//Get the position of spawn from the socket
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FireOptions")
		FName SocketForSpawnLocation = "headSocket";

public: 

	virtual void BeginPlay() override;

private:

	ACharacter* Character;

	FTimerHandle TimerHandle;

	void SpawnProjectile();

};
