
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	Health = MaxHealth;
}

float UHealthComponent::GetHealth()
{
	return Health;
}

void UHealthComponent::SetHealth(float NewHealth)
{
	Health = NewHealth;
}

float UHealthComponent::GetMaxHealth()
{
	return MaxHealth;
}

void UHealthComponent::SetMaxHealth(float NewMaxHealth)
{
	MaxHealth = NewMaxHealth;
}

void UHealthComponent::TakeDamage(float Damage)
{
	Health -= Damage;
}