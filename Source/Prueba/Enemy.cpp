
#include "Enemy.h"
#include "PruebaGameMode.h"

AEnemy::AEnemy()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetAuthGameMode<APruebaGameMode>()->AddEnemyActor(this);
}

void AEnemy::ReceiveDamage(float Damage)
{
	HealthComponent->TakeDamage(Damage);

	if (HealthComponent->GetHealth() <= 0)
	{
		GetWorld()->GetAuthGameMode<APruebaGameMode>()->RemoveEnemyActor(this);
		Destroy();
	}
}
