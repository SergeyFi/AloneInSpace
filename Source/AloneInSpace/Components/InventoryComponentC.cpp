// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponentC.h"

// Sets default values for this component's properties
UInventoryComponentC::UInventoryComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UInventoryComponentC::AddItem(UItemData* ItemData)
{
	if (ItemsMap.Contains(ItemData->ItemCategory))
	{
		if (ItemData->bIsStackable)
		{
			for (auto Item : ItemsMap[ItemData->ItemCategory].Items)
			{
				if (Item->GetClass() == ItemData->GetClass())
				{
					Item->Count += ItemData->Count;
					return;
				}
			}
		}
		else
		{
			ItemsMap[ItemData->ItemCategory].Items.Add(ItemData);
		}
	}
	else
	{
		ItemsMap.Add(ItemData->ItemCategory, {{ItemData}});
	}
	

}

void UInventoryComponentC::AddItemByActor(AActor* ItemOwner)
{
	auto ItemComponent = ItemOwner->FindComponentByClass<UItemComponentC>();

	if (ItemComponent)
	{
		AddItem(ItemComponent->GetItemData());

		ItemOwner->Destroy();
	}
}

TArray<UItemData*> UInventoryComponentC::GetItemsByCategory(TSubclassOf<UItemCategory> ItemCategory)
{
	if (ItemsMap.Contains(ItemCategory))
	{
		return ItemsMap[ItemCategory].Items;
	}

	return {};
}

TArray<TSubclassOf<UItemCategory>> UInventoryComponentC::GetCategories()
{
	TArray<TSubclassOf<UItemCategory>>  Keys;
	ItemsMap.GetKeys(Keys);
	
	return Keys;
}

void UInventoryComponentC::RemoveItem(TSubclassOf<UItemCategory> ItemCategory, UItemData* ItemData)
{
	if (ItemsMap.Contains(ItemCategory))
	{
		ItemsMap[ItemCategory].Items.Remove(ItemData);
	}
}


// Called when the game starts
void UInventoryComponentC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
