// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Damage = 50;
}

const float UHealthComponent::GetHealth()
{
	return Health;
}

void UHealthComponent::SetHealth(float HitPoints)
{
	Health = HitPoints;
	
	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("%f"), Health);
}

const bool UHealthComponent::GetDead()
{
	return bDead;
}

void UHealthComponent::SetDead(bool IsDead)
{
	bDead = IsDead;
}
