// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosWidget.generated.h"

class UDataBiosMajorSkillsWidget;
class UDataBiosMissionsWidget;
class UDataBiosTargetsWidget;
class USideMenuTab;
class UMappableWidget;
class UWidgetSwitcher;

UENUM(BlueprintType)
enum class EDataBiosSelectionRegion : uint8
{
	EDSR_Missions	UMETA(DisplayName = "Panel Missions"),
	EDSR_Targets	UMETA(DisplayName = "Panel Targets"),
	EDSR_SideMenu	UMETA(DisplayName = "Side Menu")
};

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
	UWidgetSwitcher* WidgetSwitcher;

private:
	USideMenuTab* SelectedSideTab;

	int CurrentTabIndex = 0;
	EDataBiosSelectionRegion SelectionRegion = EDataBiosSelectionRegion::EDSR_SideMenu;

private:
	void SetupWidgetMapping();
	void UpdateNewSelectedSideTab(UMappableWidget* MappableWidget, bool IsMovingUp);

};
