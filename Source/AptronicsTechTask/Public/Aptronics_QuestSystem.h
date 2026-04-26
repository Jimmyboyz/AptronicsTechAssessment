// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/DataTable.h>
#include "GameplayTagsManager.h"
#include "Kismet/BlueprintTypeConversions.h"
#include "Aptronics_QuestSystem.generated.h"

USTRUCT(BlueprintType)
struct FQuestData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText QuestTitle = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText QuestDescription = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTagContainer RequestedQuest = FGameplayTagContainer();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, int> DialogueEndTime = TMap<FGameplayTag, int>();
};


UCLASS()
class APTRONICSTECHTASK_API UAptronics_QuestSystem : public UBlueprintTypeConversions
{
	GENERATED_BODY()
	
};
