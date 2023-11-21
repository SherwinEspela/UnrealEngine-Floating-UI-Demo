// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosGroupWidget.generated.h"

class UTextBlock;
class UDataBiosWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosGroupWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;

	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionLeft();
	void MoveSelectionRight();

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
