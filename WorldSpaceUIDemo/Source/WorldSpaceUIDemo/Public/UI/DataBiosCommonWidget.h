// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosCommonWidget.generated.h"

class UUniformGridPanel;
class UMappableWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDataBiosPanelExittedSignature);

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosCommonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void MoveSelectionUp();
	virtual void MoveSelectionDown();
	virtual void MoveSelectionRight();
	virtual void MoveSelectionLeft();

	virtual void SetHighlightOnFirstMissionWidget();
	virtual void SetMenuTab(UMappableWidget* Tab) const;

public:
	FORCEINLINE UMappableWidget* GetFirstMissionWidget() const { return FirstMissionWidget; }

public:
	// Delegates
	UPROPERTY(BlueprintAssignable)
	FDataBiosPanelExittedSignature OnPanelExitted;

protected:
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* CellsGrid;

	UPROPERTY(EditAnywhere)
	bool bIsDebugging = false;

	UMappableWidget* FirstMissionWidget;
	UMappableWidget* SelectedWidget;

protected:
	virtual void UpdateNewSelectedWidget(UMappableWidget* MappableWidget);
};
