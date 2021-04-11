// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AloneInSpace/Objects/Items/ItemData.h"
#include "ItemComponentC.generated.h"



UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class ALONEINSPACE_API UItemComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemComponentC();

	UFUNCTION(BlueprintCallable, Category = "Item")
	UItemData* GetItemData();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UItemData> ItemClass;

	UPROPERTY()
	UItemData* ItemData;


private:

	void ConstructItem();
};
