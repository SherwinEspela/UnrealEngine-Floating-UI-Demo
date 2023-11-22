// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArsenalGroupWidget.generated.h"

class UTextBlock;
class UImage;
class UArsenalContentWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UArsenalGroupWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionLeft();
	void MoveSelectionRight();
	
protected:
	UPROPERTY(meta = (BindWidget))
	UArsenalContentWidget* ArsenalContents;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextArsenalName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDescription;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageTopBarBG;
};
