// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemComponentC.h"

// Sets default values for this component's properties
UItemComponentC::UItemComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

UItemData* UItemComponentC::GetItemData()
{
	return ItemData;
}


// Called when the game starts
void UItemComponentC::BeginPlay()
{
	Super::BeginPlay();

	ConstructItem();
	
}

void UItemComponentC::ConstructItem()
{
	ItemData = NewObject<UItemData>(GetOwner(), ItemClass);
}
