// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/Abstract/NavigationBaseWidget.h"
#include "DataBiosGroupWidget.generated.h"

class UTextBlock;
class UDataBiosWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosGroupWidget : public UNavigationBaseWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;

	void MoveSelectionUp() override;
	void MoveSelectionDown() override;
	void MoveSelectionLeft() override;
	void MoveSelectionRight() override;

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UDataBiosWidget* DataBios;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTitle;

private:
	UFUNCTION()
	void HandleNewTabSelected(int SelectedTabIndex);

	TArray<FString> Titles = { "PROFILE", "MAJOR SKILLS", "MISSIONS", "TARGETS" };
};
