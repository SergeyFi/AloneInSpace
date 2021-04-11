// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemAction.h"
#include "UObject/NoExportTypes.h"
#include "AloneInSpace/Objects/Items/ItemCategory.h"
#include "ItemData.generated.h"


UCLASS(Blueprintable)
class ALONEINSPACE_API UItemData : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Count;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsStackable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UItemCategory> ItemCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UItemAction* Action;
};
