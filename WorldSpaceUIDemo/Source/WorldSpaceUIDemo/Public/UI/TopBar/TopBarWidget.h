// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TopBarWidget.generated.h"

class UTopBarTabWidget;
class UMappableWidget;
class UTextBlock;
class UTopBarSideButtonWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UTopBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void MoveSelectionRight();
	void MoveSelectionLeft();

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTopBarTabWidget* TabDataBios;

	UPROPERTY(meta = (BindWidget))
	UTopBarTabWidget* TabArsenal;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextPoints;

	UPROPERTY(meta = (BindWidget))
	UTopBarSideButtonWidget* ButtonL1;

	UPROPERTY(meta = (BindWidget))
	UTopBarSideButtonWidget* ButtonR1;

private:
	void SetupWidgetMapping();
	void UpdateNewSelectedWidget(UMappableWidget* MappableWidget);

	UTopBarTabWidget* SelectedTab;
};
