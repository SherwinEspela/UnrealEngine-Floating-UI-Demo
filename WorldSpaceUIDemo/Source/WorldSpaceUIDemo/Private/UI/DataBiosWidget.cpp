// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosWidget.h"
#include "UI/SideMenuTab.h"

void UDataBiosWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupWidgetMapping();
	TabProfile->SetHighlight();
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
