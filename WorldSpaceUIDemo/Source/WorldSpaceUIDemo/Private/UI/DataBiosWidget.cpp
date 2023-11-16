// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosWidget.h"
#include "UI/SideMenuTab.h"

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
	TabTargets->SetMapAbove(TabMissions);
}

void UDataBiosWidget::MoveSelectionUp()
{
	UpdateNewSelectedSideTab(SelectedSideTab->MoveUp());
}

void UDataBiosWidget::MoveSelectionDown()
{
	UpdateNewSelectedSideTab(SelectedSideTab->MoveDown());
}

void UDataBiosWidget::UpdateNewSelectedSideTab(UMappableWidget* MappableWidget)
{
	if (MappableWidget)
	{
		SelectedSideTab->SetHighlight(false);
		SelectedSideTab = Cast<USideMenuTab>(MappableWidget);
		SelectedSideTab->SetHighlight();
	}
}
