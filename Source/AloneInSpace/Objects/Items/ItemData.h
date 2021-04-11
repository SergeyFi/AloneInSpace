// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AloneInSpace/Objects/Items/ItemCategory.h"
#include "ItemData.generated.h"


UCLASS(Blueprintable)
class ALONEINSPACE_API UItemData : public UObject
{
	GENERATED_BODY()

public:
	
	FText Name;
	int32 Count;
	bool bIsStackable;
	TSubclassOf<UItemCategory> ItemCategory;
};
