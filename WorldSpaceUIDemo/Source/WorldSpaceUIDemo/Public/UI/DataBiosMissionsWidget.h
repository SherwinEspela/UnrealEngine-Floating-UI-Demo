// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/DataBiosCommonWidget.h"
#include "DataBiosMissionsWidget.generated.h"

class UMissionWidget;

USTRUCT(BlueprintType)
struct FMissionRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* MissionIcon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString MissionName = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Difficulty = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsCompleted = false;
};

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosMissionsWidget : public UDataBiosCommonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UDataTable* MissionsDataTable;

protected:
	void NativeConstruct() override;
	void NativePreConstruct() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMissionWidget> MissionWidgetClass;

private:
	void LoadCells();
};
