// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/DataBiosCommonWidget.h"
#include "UI/MappableWidget.h"
#include "DataBiosMissionsWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMissionPanelExittedSignature);

class UMissionWidget;
class UMappableWidget;

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

public:
	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionRight();
	void MoveSelectionLeft();

	void SetHighlightOnFirstMissionWidget();
	void SetMissionTab(UMappableWidget *MissionTab);

public:
	FORCEINLINE UMappableWidget* GetFirstMissionWidget() const { return FirstMissionWidget; }

public:
	// Delegates
	UPROPERTY(BlueprintAssignable)
	FMissionPanelExittedSignature OnMissionPanelExitted;

protected:
	void NativeConstruct() override;
	void NativePreConstruct() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMissionWidget> MissionWidgetClass;

private:
	void LoadCells();
	void SetupWidgetMapping();

	TArray<UMissionWidget*> MissionWidgets;

	UMappableWidget* FirstMissionWidget;
	UMissionWidget* SelectedWidget;

	void UpdateNewSelectedWidget(UMappableWidget* MappableWidget);
};
