// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosWidget.h"
#include "UI/SideMenuTab.h"
#include "Components/WidgetSwitcher.h"
#include "UI/DataBiosMissionsWidget.h"

void UDataBiosWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupWidgetMapping();
	TabProfile->SetHighlight();
	SelectedSideTab = TabProfile;

	Missions->OnMissionPanelExitted.AddDynamic(this, &UDataBiosWidget::HandlePanelExitted);
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

	SelectionRegion = EDataBiosSelectionRegion::EDSR_SideMenu;
}

void UDataBiosWidget::MoveSelectionUp()
{
	switch (SelectionRegion)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			Missions->MoveSelectionUp();
			break;
		case EDataBiosSelectionRegion::EDSR_Targets:
			break;
		case EDataBiosSelectionRegion::EDSR_SideMenu:
			UpdateNewSelectedSideTab(SelectedSideTab->MoveUp(), true);
			break;
		default:
			break;
	}
}

void UDataBiosWidget::MoveSelectionDown()
{
	switch (SelectionRegion)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			Missions->MoveSelectionDown();
			break;
		case EDataBiosSelectionRegion::EDSR_Targets:
			break;
		case EDataBiosSelectionRegion::EDSR_SideMenu:
			UpdateNewSelectedSideTab(SelectedSideTab->MoveDown(), false);
			break;
		default:
			break;
	}
}

void UDataBiosWidget::MoveSelectionRight()
{
	switch (SelectionRegion)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			Missions->MoveSelectionRight();
			break;
		case EDataBiosSelectionRegion::EDSR_Targets:
			break;
		case EDataBiosSelectionRegion::EDSR_SideMenu:
			UMappableWidget* NewWidget = SelectedSideTab->MoveRight();
			if (NewWidget)
			{
				SelectionRegion = NewWidget->GetSelectionRegion();				
				switch (SelectionRegion)
				{
					case EDataBiosSelectionRegion::EDSR_Missions:
						Missions->SetHighlightOnFirstMissionWidget();
						Missions->SetMissionTab(TabMissions);
						break;
					case EDataBiosSelectionRegion::EDSR_Targets:
						break;
					case EDataBiosSelectionRegion::EDSR_SideMenu:
						break;
				}
			}	
			break;
	}
}

void UDataBiosWidget::MoveSelectionLeft()
{
	switch (SelectionRegion)
	{
	case EDataBiosSelectionRegion::EDSR_Missions:
		Missions->MoveSelectionLeft();
		break;
	case EDataBiosSelectionRegion::EDSR_Targets:
		break;
	case EDataBiosSelectionRegion::EDSR_SideMenu:
		break;
	}

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

void UDataBiosWidget::HandlePanelExitted()
{
	SelectionRegion = EDataBiosSelectionRegion::EDSR_SideMenu;
}
