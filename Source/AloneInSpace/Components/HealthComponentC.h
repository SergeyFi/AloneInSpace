// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALONEINSPACE_API UHealthComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponentC();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Heal);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void RemoveHealth(float Damage);

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float HealthMax;

		
};
