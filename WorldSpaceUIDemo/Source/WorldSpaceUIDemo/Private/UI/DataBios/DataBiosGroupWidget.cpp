// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/DataBiosGroupWidget.h"
#include "UI/DataBiosWidget.h"

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
