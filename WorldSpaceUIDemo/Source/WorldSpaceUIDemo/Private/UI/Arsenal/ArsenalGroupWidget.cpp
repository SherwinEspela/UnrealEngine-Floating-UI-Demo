// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalGroupWidget.h"
#include "UI/Arsenal/ArsenalContentWidget.h"

void UArsenalGroupWidget::MoveSelectionUp()
{
	ArsenalContents->MoveSelectionUp();
}

void UArsenalGroupWidget::MoveSelectionDown()
{
	ArsenalContents->MoveSelectionDown();
}

void UArsenalGroupWidget::MoveSelectionLeft()
{
	ArsenalContents->MoveSelectionLeft();
}

void UArsenalGroupWidget::MoveSelectionRight()
{
	ArsenalContents->MoveSelectionRight();
}
