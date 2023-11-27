// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosWidget.h"
#include "UI/SideMenuTab.h"
#include "Components/WidgetSwitcher.h"
#include "UI/DataBiosMissionsWidget.h"
#include "UI/DataBios/DataBiosTargetsWidget.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

void UDataBiosWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupWidgetMapping();
	Reset();

	Missions->OnPanelExitted.AddDynamic(this, &UDataBiosWidget::HandlePanelExitted);
	Targets->OnPanelExitted.AddDynamic(this, &UDataBiosWidget::HandlePanelExitted);

	ThemeManager::SetTransparentBackgroundColor(ImageSideMenuBG);
}

void UDataBiosWidget::SetupWidgetMapping()
{
	TabProfile->SetMapBelow(TabMainSkills);
	TabMainSkills->SetMapAbove(TabProfile);
	TabMainSkills->SetMapBelow(TabMissions);
	TabMissions->SetMapAbove(TabMainSkills);
	TabMissions->SetMapBelow(TabTargets);
	TabMissions->SetMapOnRight(Missions->GetFirstElementWidget());
	TabTargets->SetMapAbove(TabMissions);
	TabTargets->SetMapOnRight(Targets->GetFirstElementWidget());

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
			Targets->MoveSelectionUp();
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
			Targets->MoveSelectionDown();
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
			Targets->MoveSelectionRight();
			break;
		case EDataBiosSelectionRegion::EDSR_SideMenu:
			UMappableWidget* NewWidget = SelectedSideTab->MoveRight();
			
			if (NewWidget)
			{
				SelectionRegion = NewWidget->GetSelectionRegion();
				OnSelectedRegionChanged.Broadcast(SelectionRegion);
				
				switch (SelectionRegion)
				{
					case EDataBiosSelectionRegion::EDSR_Missions:
						Missions->SetHighlightOnFirstElementWidget();
						Missions->SetMenuTab(TabMissions);
						break;
					case EDataBiosSelectionRegion::EDSR_Targets:
						Targets->SetHighlightOnFirstElementWidget();
						Targets->SetMenuTab(TabTargets);
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
		Targets->MoveSelectionLeft();
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
		OnNewTabSelected.Broadcast(CurrentTabIndex);
	}
}

void UDataBiosWidget::HandlePanelExitted()
{
	SelectionRegion = EDataBiosSelectionRegion::EDSR_SideMenu;
	OnSelectedRegionChanged.Broadcast(SelectionRegion);
}

FName UDataBiosWidget::GetRowNameFromSelectedWidget() const
{
	switch (SelectionRegion)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			return Missions->GetRowNameFromSelectedWidget();
		case EDataBiosSelectionRegion::EDSR_Targets:
			return Targets->GetRowNameFromSelectedWidget();
		default:
			return FName();
	}

	return FName();
}

void UDataBiosWidget::Reset()
{
	if (SelectedSideTab) SelectedSideTab->SetHighlight(false);

	TabProfile->SetHighlight();
	SelectedSideTab = TabProfile;
	CurrentTabIndex = 0;
	WidgetSwitcher->SetActiveWidgetIndex(CurrentTabIndex);
	SelectionRegion = EDataBiosSelectionRegion::EDSR_SideMenu;

	Missions->Reset();
	Targets->Reset();
}
