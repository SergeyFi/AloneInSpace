// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OxygenComponentC.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOxygenDelegate, float, Oxygen);

UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class ALONEINSPACE_API UOxygenComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOxygenComponentC();

	UFUNCTION(BlueprintCallable, Category = "Oxygen")
	void AddOxygen(float OxygenAmount);

	UFUNCTION(BlueprintCallable, Category = "Oxygen")
	void RemoveOxygen(float OxygenDamage);

	UFUNCTION(BlueprintPure, Category = "Oxygen")
	float GetOxygen();

	UFUNCTION(BlueprintCallable, Category = "Oxygen")
	void AddOxygenSpending(float OxySpend);

	UFUNCTION(BlueprintCallable, Category = "Oxygen")
	void RemoveOxygenSpending(float OxySpend);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Oxygen")
	float Oxygen;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Oxygen")
	float OxygenMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Oxygen")
	float OxygenSpending;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Oxygen")
	float OxygenSpendingRate;

	void OxygenSpend();

	void StartOxygenSpending();

	FTimerHandle OxygenSpendTimer;

	UPROPERTY(BlueprintAssignable, Category = "Oxygen")
	FOxygenDelegate OnOxygenEnd;

	UPROPERTY(BlueprintAssignable, Category = "Oxygen")
	FOxygenDelegate OnOxygenAdd;
};
