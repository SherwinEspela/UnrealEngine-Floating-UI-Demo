// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/DataBios/DataBiosGroupWidget.h"
#include "UI/Arsenal//ArsenalGroupWidget.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (DotGrid)
	{
		DotGrid->SetMinDesiredSlotWidth(DotSize);
		DotGrid->SetMinDesiredSlotHeight(DotSize);

		for (size_t row = 0; row < DotCount; row++)
		{
			for (size_t col = 0; col < DotCount; col++)
			{
				UUserWidget* Dot = CreateWidget<UUserWidget>(GetWorld(), TilableDotClass);
				DotGrid->AddChildToUniformGrid(Dot, row, col);
			}
		}
	}
}

void UMainMenuWidget::MoveSelectionUp()
{
	if (bIsViewingDataBios)
	{
		DataBiosGroup->MoveSelectionUp();
	}
	else {
		ArsenalGroup->MoveSelectionUp();
	}
}

void UMainMenuWidget::MoveSelectionDown()
{
	if (DataBiosGroup) DataBiosGroup->MoveSelectionDown();
}

void UMainMenuWidget::MoveSelectionLeft()
{
	if (DataBiosGroup) DataBiosGroup->MoveSelectionLeft();
}

void UMainMenuWidget::MoveSelectionRight()
{
	if (DataBiosGroup) DataBiosGroup->MoveSelectionRight();
}

void UMainMenuWidget::MoveTopBarSelectionLeft()
{
	if (TopBar) TopBar->MoveSelectionLeft();
	bIsViewingDataBios = true;
}

void UMainMenuWidget::MoveTopBarSelectionRight()
{
	if (TopBar) TopBar->MoveSelectionRight();
	bIsViewingDataBios = false;
}
