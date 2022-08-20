
#include "BoxEnemy.h"
#include "Components/BoxComponent.h"

ABoxEnemy::ABoxEnemy()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionBox->SetupAttachment(RootComponent);
}
