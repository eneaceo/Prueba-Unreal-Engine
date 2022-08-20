
#include "CapsuleEnemy.h"
#include "Components/CapsuleComponent.h"

ACapsuleEnemy::ACapsuleEnemy()
{
	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
	CollisionCapsule->SetupAttachment(RootComponent);
}