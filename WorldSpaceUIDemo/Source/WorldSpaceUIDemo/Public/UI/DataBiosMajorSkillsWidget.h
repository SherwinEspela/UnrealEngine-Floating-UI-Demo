// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "DataBiosMajorSkillsWidget.generated.h"

class UUniformGridPanel;
class UDataTable;
class USkillWidget;

USTRUCT(BlueprintType)
struct FMajorSkillsRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* SkillIcon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString SkillName = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Level = 1;
};

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosMajorSkillsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UDataTable* SkillsDataTable;

protected:
	void NativeConstruct() override;
	void NativePreConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* SkillsGrid;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USkillWidget> SkillWidgetClass;
};
