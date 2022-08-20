
#include "ProjectileSpawnerComponent.h"
#include "GameFramework/Character.h"
#include "Projectile.h"

void UProjectileSpawnerComponent::Fire()
{
	//Compensate first projectile delay
	SpawnProjectile();
	//Looping timer
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UProjectileSpawnerComponent::SpawnProjectile, FireRate, bAutomaticFire);
}

void UProjectileSpawnerComponent::StopFire()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void UProjectileSpawnerComponent::SpawnProjectile()
{
	if (!ProjectileClass || !Character->GetMesh()->DoesSocketExist(SocketForSpawnLocation))
	{
		return;
	}
	
	// Get spawn transform
	FTransform Transform;
	Transform.SetLocation(Character->GetMesh()->GetSocketLocation(SocketForSpawnLocation));
	Transform.SetRotation(Character->GetActorRotation().Quaternion());

	// Spawn projectile
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Transform, SpawnParams);
}

void UProjectileSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Cannot get owner actor ... "), *GetName());
		return;
	}

	Character = Cast<ACharacter>(GetOwner());
	if (!Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Cannot cast character ... "), *GetName());
		return;
	}
}
