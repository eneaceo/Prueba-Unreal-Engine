#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "Projectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS(Blueprintable, Abstract)
class AProjectile : public AActor
{
	GENERATED_BODY()

public:

	AProjectile();

protected:
	
	UPROPERTY(EditDefaultsOnly)
		USphereComponent* SphereCollision = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
		float Damage = 10.0f;

public:

	UFUNCTION()
	void OnOverlapCollisionSphere(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
