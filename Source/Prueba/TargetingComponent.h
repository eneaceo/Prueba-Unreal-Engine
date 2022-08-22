
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBA_API UTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UTargetingComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0.0"), Category = "Targeting")
		float MaxTargetRange = 2000.0f;

	UFUNCTION(BlueprintCallable, Category = "Targeting")
		void TargetLockOff();

	UFUNCTION(BlueprintCallable, Category = "Targeting")
		void FindTarget();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting | Debug")
		bool bDrawDebug = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting |Pitch Offset")
		float PitchDistanceCoefficient = -0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting |Pitch Offset")
		float PitchDistanceOffset = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting |Pitch Offset")
		float PitchMin = -50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting |Pitch Offset")
		float PitchMax = -20.0f;

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY()
		AActor* OwnerActor;

	UPROPERTY()
		APawn* OwnerPawn;

	UPROPERTY()
		AController* OwnerController;

	AActor* LockedOnTargetActor;

	bool bTargetLocked = false;

	AActor* FindNearestTarget(TArray<AActor*> Actors) const;
	void TargetLockOn(AActor* TargetToLockOn);

	//~ Actor rotation
	void ControlRotation(const bool ControlRotation) const;
	FRotator GetControlRotationOnTarget(const AActor* OtherActor) const;
	void SetControlRotationOnTarget(AActor* TargetActor);
	
};
