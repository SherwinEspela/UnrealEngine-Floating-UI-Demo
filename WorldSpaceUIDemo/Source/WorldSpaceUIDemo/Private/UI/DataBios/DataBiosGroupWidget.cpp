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
