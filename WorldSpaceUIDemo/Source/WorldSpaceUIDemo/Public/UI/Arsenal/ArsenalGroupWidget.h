// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/Abstract/NavigationBaseWidget.h"
#include "ArsenalGroupWidget.generated.h"

class UTextBlock;
class UImage;
class UArsenalContentWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UArsenalGroupWidget : public UNavigationBaseWidget
{
	GENERATED_BODY()

public:
	void MoveSelectionUp() override;
	void MoveSelectionDown() override;
	void MoveSelectionLeft() override;
	void MoveSelectionRight() override;
	
protected:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UArsenalContentWidget* ArsenalContents;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextArsenalName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDescription;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageTopBarBG;

private:
	UFUNCTION()
	void HandleArsenalWidgetSelected(FString ArsenalName, FString Description);
};
