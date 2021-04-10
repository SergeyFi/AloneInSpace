// Fill out your copyright notice in the Description page of Project Settings.


#include "OxygenComponentC.h"

// Sets default values for this component's properties
UOxygenComponentC::UOxygenComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UOxygenComponentC::AddOxygen(float OxygenAmount)
{
	Oxygen += OxygenAmount;

	if (Oxygen > OxygenMax)
	{
		Oxygen = OxygenMax;
	}

	OnOxygenAdd.Broadcast(Oxygen);
}

void UOxygenComponentC::RemoveOxygen(float OxygenDamage)
{
	Oxygen -= OxygenDamage;

	if (Oxygen < 0.0f)
	{
		Oxygen = 0.0f;
	}

	if (Oxygen <= 0.0f)
	{
		OnOxygenEnd.Broadcast(Oxygen);
	}
}

float UOxygenComponentC::GetOxygen()
{
	return Oxygen;
}

void UOxygenComponentC::AddOxygenSpending(float OxySpend)
{
	OxygenSpending += OxySpend;
}

void UOxygenComponentC::RemoveOxygenSpending(float OxySpend)
{
	OxygenSpending -= OxySpend;

	if (OxygenSpending < 0.0f)
	{
		OxygenSpending = 0.0f;
	}
}


// Called when the game starts
void UOxygenComponentC::BeginPlay()
{
	Super::BeginPlay();

	StartOxygenSpending();
}

void UOxygenComponentC::OxygenSpend()
{
	RemoveOxygen(OxygenSpending * OxygenSpendingRate);
}

void UOxygenComponentC::StartOxygenSpending()
{
	GetWorld()->GetTimerManager().SetTimer(OxygenSpendTimer, this, &UOxygenComponentC::OxygenSpend, OxygenSpendingRate, true);
}
