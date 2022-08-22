
#include "HealthBar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "HealthComponent.h"

void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!Owner.IsValid()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Owner not valid ... "), *GetName());
		return;
	}

	if (UHealthComponent* HealthComponent = Cast<UHealthComponent>(Owner->GetComponentByClass(UHealthComponent::StaticClass())))
	{
		HealthBar->SetPercent(HealthComponent->GetHealth() / HealthComponent->GetMaxHealth());
		HealthLabel->SetText(FText::AsNumber(HealthComponent->GetHealth()));
		MaxHealthLabel->SetText(FText::AsNumber(HealthComponent->GetMaxHealth()));
	}
}