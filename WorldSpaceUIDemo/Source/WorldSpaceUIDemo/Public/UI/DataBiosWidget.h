// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomEnums.h"
#include "DataBiosWidget.generated.h"

class UDataBiosMajorSkillsWidget;
class UDataBiosMissionsWidget;
class UDataBiosTargetsWidget;
class UDataBiosProfileWidget;
class USideMenuTab;
class UMappableWidget;
class UWidgetSwitcher;
class UImage;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewTabSelectedSignature, int, SelectedTabIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataBiosSelectedRegionChangedSignature, EDataBiosSelectionRegion, SelectedRegion);

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionRight();
	void MoveSelectionLeft();
	void ShouldPlayProfileFX(bool ShouldPlay);
	void Reset();

	FOnNewTabSelectedSignature OnNewTabSelected;
	FOnDataBiosSelectedRegionChangedSignature OnSelectedRegionChanged;

public:
	FName GetRowNameFromSelectedWidget() const;

protected:
	void NativeConstruct() override;

	// Side Menu Tabs
	UPROPERTY(meta = (BindWidget))
	USideMenuTab* TabProfile;

	UPROPERTY(meta = (BindWidget))
	USideMenuTab* TabMainSkills;

	UPROPERTY(meta = (BindWidget))
	USideMenuTab* TabMissions;

	UPROPERTY(meta = (BindWidget))
	USideMenuTab* TabTargets;

	UPROPERTY(meta = (BindWidget))
	UDataBiosMissionsWidget* Missions;

	UPROPERTY(meta = (BindWidget))
	UDataBiosTargetsWidget* Targets;

	UPROPERTY(meta = (BindWidget))
	UDataBiosProfileWidget* Profile;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* WidgetSwitcher;

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageSideMenuBG;

	UPROPERTY(EditAnywhere)
	USoundBase* SfxTabSelect;

private:
	USideMenuTab* SelectedSideTab;

	int CurrentTabIndex = 0;
	EDataBiosSelectionRegion SelectionRegion = EDataBiosSelectionRegion::EDSR_SideMenu;

private:
	void SetupWidgetMapping();
	void UpdateNewSelectedSideTab(UMappableWidget* MappableWidget, bool IsMovingUp);

private:
	UFUNCTION()
	void HandlePanelExitted();
};
