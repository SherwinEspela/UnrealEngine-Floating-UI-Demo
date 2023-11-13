// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosWidget.generated.h"

class UDataBiosMajorSkillsWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UDataBiosMajorSkillsWidget* MajorSkillsWidget;
};
