// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemData.h"

UItemData::UItemData()
{
	if (ActionClass && GetOuter())
	{
		Action = NewObject<UItemAction>(GetOuter(), ActionClass);
	}
}
