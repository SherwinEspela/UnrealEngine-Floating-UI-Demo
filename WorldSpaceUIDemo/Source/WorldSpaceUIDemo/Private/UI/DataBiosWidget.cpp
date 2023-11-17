// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosWidget.h"
#include "UI/SideMenuTab.h"
#include "Components/WidgetSwitcher.h"

void UDataBiosWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupWidgetMapping();
	TabProfile->SetHighlight();
	SelectedSideTab = TabProfile;
}

void UDataBiosWidget::SetupWidgetMapping()
{
	TabProfile->SetMapBelow(TabMainSkills);
	TabMainSkills->SetMapAbove(TabProfile);
	TabMainSkills->SetMapBelow(TabMissions);
	TabMissions->SetMapAbove(TabMainSkills);
	TabMissions->SetMapBelow(TabTargets);
	TabMissions->SetMapOnRight(Missions->GetFirstMissionWidget());
	TabTargets->SetMapAbove(TabMissions);
}

void UDataBiosWidget::MoveSelectionUp()
{
	UpdateNewSelectedSideTab(SelectedSideTab->MoveUp(), true);
}

void UDataBiosWidget::MoveSelectionDown()
{
	UpdateNewSelectedSideTab(SelectedSideTab->MoveDown(), false);
}

void UDataBiosWidget::MoveSelectionRight()
{
	switch (SelectionRegion)
	{
	case EDataBiosSelectionRegion::EDSR_Missions:
		break;
	case EDataBiosSelectionRegion::EDSR_Targets:
		break;
	case EDataBiosSelectionRegion::EDSR_SideMenu:
		UMappableWidget* Widget = SelectedSideTab->MoveRight();
		
		break;
	default:
		break;
	}
}

void UDataBiosWidget::MoveSelectionLeft()
{

}

void UDataBiosWidget::UpdateNewSelectedSideTab(UMappableWidget* MappableWidget, bool IsMovingUp)
{
	if (MappableWidget)
	{
		SelectedSideTab->SetHighlight(false);
		SelectedSideTab = Cast<USideMenuTab>(MappableWidget);
		SelectedSideTab->SetHighlight();
		CurrentTabIndex = IsMovingUp ? --CurrentTabIndex : ++CurrentTabIndex;
		WidgetSwitcher->SetActiveWidgetIndex(CurrentTabIndex);
	}
}
