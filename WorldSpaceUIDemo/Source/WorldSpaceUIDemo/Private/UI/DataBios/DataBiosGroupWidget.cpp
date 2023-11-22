// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/DataBiosGroupWidget.h"
#include "UI/DataBiosWidget.h"
#include "Components/TextBlock.h"

void UDataBiosGroupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	DataBios->OnNewTabSelected.AddDynamic(this, &UDataBiosGroupWidget::HandleNewTabSelected);
}

void UDataBiosGroupWidget::MoveSelectionUp()
{
	if (DataBios)
	{
		DataBios->MoveSelectionUp();
	}
}

void UDataBiosGroupWidget::MoveSelectionDown()
{
	if (DataBios)
	{
		DataBios->MoveSelectionDown();
	}
}

void UDataBiosGroupWidget::MoveSelectionLeft()
{
	if (DataBios)
	{
		DataBios->MoveSelectionLeft();
	}
}

void UDataBiosGroupWidget::MoveSelectionRight()
{
	if (DataBios)
	{
		DataBios->MoveSelectionRight();
	}
}

FName UDataBiosGroupWidget::GetRowNameFromSelectedWidget() const
{
	return DataBios->GetRowNameFromSelectedWidget();
}

void UDataBiosGroupWidget::HandleNewTabSelected(int SelectedTabIndex)
{
	TextTitle->SetText(FText::FromString(Titles[SelectedTabIndex]));
}
