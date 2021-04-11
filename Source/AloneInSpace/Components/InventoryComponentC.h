// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AloneInSpace/Components/ItemComponentC.h"
#include "InventoryComponentC.generated.h"

USTRUCT()
struct FItems
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UItemData*> Items;
};

UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class ALONEINSPACE_API UInventoryComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponentC();
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UItemData* ItemData);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemByActor(AActor* ItemOwner);

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<UItemData*> GetItemsByCategory(TSubclassOf<UItemCategory> ItemCategory);

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<TSubclassOf<UItemCategory>> GetCategories();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(TSubclassOf<UItemCategory> ItemCategory, UItemData* ItemData);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TMap<TSubclassOf<UItemCategory>, FItems> ItemsMap;

		
};
