// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TopBarWidget.generated.h"

class UTopBarTabWidget;
class UMappableWidget;
class UTextBlock;

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

private:
	void SetupWidgetMapping();
	void UpdateNewSelectedWidget(UMappableWidget* MappableWidget);

	UTopBarTabWidget* SelectedTab;
};
