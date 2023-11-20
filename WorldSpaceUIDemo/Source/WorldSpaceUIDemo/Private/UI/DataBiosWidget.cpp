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
			break;
		case EDataBiosSelectionRegion::EDSR_Targets:
			break;
		case EDataBiosSelectionRegion::EDSR_SideMenu:
			UE_LOG(LogTemp, Warning, TEXT("UDataBiosWidget::MoveSelectionRight"));
			//UMappableWidget* NewWidget = SelectedSideTab->MoveRight();
			//SelectionRegion = NewWidget->GetSelectionRegion();
			//UE_LOG(LogTemp, Warning, TEXT("NewWidget ====== %s"), *NewWidget->GetName())
			break;
	}
}

void UDataBiosWidget::MoveSelectionLeft()
{
	switch (SelectionRegion)
	{
	case EDataBiosSelectionRegion::EDSR_Missions:
		break;
	case EDataBiosSelectionRegion::EDSR_Targets:
		break;
	case EDataBiosSelectionRegion::EDSR_SideMenu:
		UE_LOG(LogTemp, Warning, TEXT("UDataBiosWidget::MoveSelectionLeft"));
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
