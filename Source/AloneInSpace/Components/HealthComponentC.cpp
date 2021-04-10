// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponentC.h"

// Sets default values for this component's properties
UHealthComponentC::UHealthComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}

void UHealthComponentC::AddHealth(float Heal)
{
	Health += Heal;

	if (Health > HealthMax)
	{
		Health = HealthMax;
	}
}

void UHealthComponentC::RemoveHealth(float Damage)
{
	Health -= Damage;

	if (Health < 0.0f)
	{
		Health = 0.0f;
	}
}

float UHealthComponentC::GetHealth()
{
	return Health;
}


// Called when the game starts
void UHealthComponentC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
