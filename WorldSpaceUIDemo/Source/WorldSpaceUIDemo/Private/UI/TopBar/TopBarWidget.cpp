// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/TopBar/TopBarWidget.h"
#include "UI/TopBar/TopBarTabWidget.h"
#include "Components/TextBlock.h"
#include "Utility/ThemeManager.h"
#include "UI/TopBar/TopBarSideButtonWidget.h"
#include "Utility/ThemeManager.h"

void UTopBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetupWidgetMapping();
	Reset();
	ThemeManager::SetTextToDefault(TextPoints);
	ThemeManager::SetBackgroundColor(ImagePointsIcon, COLOR_TEXT_DEFAULT1);
}

void UTopBarWidget::SetupWidgetMapping()
{
	TabDataBios->SetMapOnRight(TabArsenal);
	TabArsenal->SetMapOnLeft(TabDataBios);
}

void UTopBarWidget::MoveSelectionRight()
{
	UpdateNewSelectedWidget(SelectedTab->MoveRight());
	ButtonR1->OnSideButtonTapped();
}

void UTopBarWidget::MoveSelectionLeft()
{
	UpdateNewSelectedWidget(SelectedTab->MoveLeft());
	ButtonL1->OnSideButtonTapped();
}

void UTopBarWidget::UpdateNewSelectedWidget(UMappableWidget* MappableWidget)
{
	if (MappableWidget)
	{
		SelectedTab->SetHighlight(false);
		SelectedTab = Cast<UTopBarTabWidget>(MappableWidget);
		SelectedTab->SetHighlight();
	}
}

void UTopBarWidget::Reset()
{
	TabDataBios->SetHighlight();
	TabArsenal->SetHighlight(false);
	SelectedTab = TabDataBios;
}
