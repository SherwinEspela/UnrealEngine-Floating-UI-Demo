// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosCommonWidget.h"
#include "UI/MappableWidget.h"

void UDataBiosCommonWidget::MoveSelectionUp()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveUp());
}

void UDataBiosCommonWidget::MoveSelectionDown()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveDown());
}

void UDataBiosCommonWidget::MoveSelectionLeft()
{
	if (SelectedWidget->bIsExit)
	{
		OnPanelExitted.Broadcast();
	}
	else {
		UpdateNewSelectedWidget(SelectedWidget->MoveLeft());
	}
}

void UDataBiosCommonWidget::MoveSelectionRight()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveRight());
}

void UDataBiosCommonWidget::UpdateNewSelectedWidget(UMappableWidget* MappableWidget)
{
}

void UDataBiosCommonWidget::SetHighlightOnFirstElementWidget()
{	
}

void UDataBiosCommonWidget::SetMenuTab(UMappableWidget* Tab) const
{
}

FName UDataBiosCommonWidget::GetRowNameFromSelectedWidget() const
{
	return FName();
}
