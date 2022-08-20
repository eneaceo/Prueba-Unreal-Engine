
#include "Enemy.h"
#include "PruebaGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "HealthBar.h"

AEnemy::AEnemy()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	HealthWidget = CreateDefaultSubobject<UWidgetComponent>("HealthWidget");
	HealthWidget->SetupAttachment(RootComponent);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetAuthGameMode<APruebaGameMode>()->AddEnemyActor(this);

	if (UHealthBar* HealthBar = Cast<UHealthBar>(HealthWidget->GetUserWidgetObject()))
	{
		HealthBar->SetOwner(this);
		bool bLooping = true;
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemy::RotateHealthBar, HealthWidgetRotationRate, bLooping);
	}
}

void AEnemy::RotateHealthBar()
{
	if (APlayerCameraManager* CameraManager = Cast<APlayerCameraManager>(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)))
	{
		FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(HealthWidget->GetComponentLocation(), CameraManager->GetCameraLocation());
		HealthWidget->SetWorldRotation(Rotation);
	}
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
