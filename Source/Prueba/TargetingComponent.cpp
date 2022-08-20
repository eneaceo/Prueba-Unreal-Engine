
#include "TargetingComponent.h"
#include "PruebaGameMode.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"

UTargetingComponent::UTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTargetingComponent::BeginPlay()
{
	Super::BeginPlay();

	//Checks
	OwnerActor = GetOwner();
	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Cannot get owner actor ... "), *GetName());
		return;
	}

	OwnerPawn = Cast<APawn>(OwnerActor);
	if (!ensure(OwnerPawn) || !OwnerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Cannot get owner pawn ... "), *GetName());
		return;
	}

	OwnerController = Cast<AController>(OwnerPawn->GetController());
	if (!OwnerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Cannot get owner controller ... "), *GetName());
		return;
	}
}


void UTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Target is not locked
	if (!bTargetLocked || !LockedOnTargetActor)
	{
		return;
	}

	if (LockedOnTargetActor->IsPendingKill())
	{
		TargetLockOff();
		TargetActor();
	}
	else
	{
		//Set rotation of player to Target Locked
		SetControlRotationOnTarget(LockedOnTargetActor);
		DrawDebugLine(GetWorld(), OwnerActor->GetActorLocation(), LockedOnTargetActor->GetActorLocation(), FColor(0, 0, 255), false, 1.0f, 0, 1);
	}
}

void UTargetingComponent::TargetActor()
{
	if (bTargetLocked)
	{
		TargetLockOff();
	}
	else
	{
		FindTarget();
	}
}

void UTargetingComponent::FindTarget()
{
	TArray < AActor* >& AllEnemies = GetWorld()->GetAuthGameMode<APruebaGameMode>()->GetEnemyActorsRef();
	if (AllEnemies.Num() != 0)
	{
		LockedOnTargetActor = FindNearestTarget(AllEnemies);
		TargetLockOn(LockedOnTargetActor);
	}
}

void UTargetingComponent::TargetLockOff()
{
	bTargetLocked = false;
	LockedOnTargetActor = nullptr;

	ControlRotation(false);

	//Ignore controller input reset
	OwnerController->ResetIgnoreLookInput();
}

void UTargetingComponent::TargetLockOn(AActor* TargetToLockOn)
{
	if (!IsValid(TargetToLockOn))
	{
		return;
	}

	bTargetLocked = true;

	//Ignore character orientation
	ControlRotation(true);

	//Ignore controller input
	OwnerController->SetIgnoreLookInput(true);
}

AActor* UTargetingComponent::FindNearestTarget(TArray<AActor*> Actors) const
{
	//Check the closest actor
	float ClosestDistance = MaxTargetRange;
	AActor* Target = nullptr;
	for (AActor* Actor : Actors)
	{
		const float Distance = OwnerActor->GetDistanceTo(Actor);
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			Target = Actor;
		}
	}

	return Target;
}

void UTargetingComponent::SetControlRotationOnTarget(AActor* TargetActor)
{
	FRotator ControlRotation = GetControlRotationOnTarget(TargetActor);
	OwnerController->SetControlRotation(ControlRotation);
}

FRotator UTargetingComponent::GetControlRotationOnTarget(const AActor* OtherActor) const
{
	const FRotator ControlRotation = OwnerController->GetControlRotation();

	const FVector CharacterLocation = OwnerActor->GetActorLocation();
	const FVector OtherActorLocation = OtherActor->GetActorLocation();

	const FRotator LookRotation = FRotationMatrix::MakeFromX(OtherActorLocation - CharacterLocation).Rotator();
	float Pitch = LookRotation.Pitch;
	FRotator TargetRotation;

	const float DistanceToTarget = OwnerActor->GetDistanceTo(OtherActor);
	const float PitchInRange = (DistanceToTarget * PitchDistanceCoefficient + PitchDistanceOffset) * -1.0f;
	const float PitchOffset = FMath::Clamp(PitchInRange, PitchMin, PitchMax);

	Pitch = Pitch + PitchOffset;
	TargetRotation = FRotator(Pitch, LookRotation.Yaw, ControlRotation.Roll);

	return FMath::RInterpTo(ControlRotation, TargetRotation, GetWorld()->GetDeltaSeconds(), 9.0f);
}

void UTargetingComponent::ControlRotation(const bool ControlRotation) const
{

	OwnerPawn->bUseControllerRotationYaw = ControlRotation;

	UCharacterMovementComponent* CharacterMovementComponent = OwnerPawn->FindComponentByClass<UCharacterMovementComponent>();
	if (CharacterMovementComponent)
	{
		CharacterMovementComponent->bOrientRotationToMovement = !ControlRotation;
	}
}