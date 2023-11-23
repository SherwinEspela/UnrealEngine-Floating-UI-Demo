// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/Abstract/NavigationBaseWidget.h"
#include "CustomEnums.h"
#include "DataBiosGroupWidget.generated.h"

class UTextBlock;
class UDataBiosWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectedRegionChangedSignature, EDataBiosSelectionRegion, SelectedRegion);

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
	void Reset();

	FName GetRowNameFromSelectedWidget() const;
	FOnSelectedRegionChangedSignature OnSelectedRegionChanged;

public:
	FORCEINLINE EDataBiosSelectionRegion GetCurrentSelectedTabType() const { return CurrentSelectedTabType; }

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UDataBiosWidget* DataBios;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTitle;

private:
	UFUNCTION()
	void HandleNewTabSelected(int SelectedTabIndex);

	UFUNCTION()
	void HandleSelectedRegionChanged(EDataBiosSelectionRegion SelectedRegion);

	TArray<FString> Titles = { "PROFILE", "MAJOR SKILLS", "MISSIONS", "TARGETS" };
	EDataBiosSelectionRegion CurrentSelectedTabType;
};
