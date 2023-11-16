// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosWidget.generated.h"

class UDataBiosMajorSkillsWidget;
class USideMenuTab;
class UMappableWidget;

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
	UDataBiosMajorSkillsWidget* MajorSkillsWidget;

private:
	USideMenuTab* SelectedSideTab;

private:
	void SetupWidgetMapping();
	void UpdateNewSelectedSideTab(UMappableWidget* MappableWidget);

};
