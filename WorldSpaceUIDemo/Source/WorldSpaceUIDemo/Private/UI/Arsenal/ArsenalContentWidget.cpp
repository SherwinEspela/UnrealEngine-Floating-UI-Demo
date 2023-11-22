// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalContentWidget.h"
#include "UI/Arsenal/ArsenalCellWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/MappableWidget.h"

void UArsenalContentWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	LoadAllCells();
}

void UArsenalContentWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetupWidgetMapping();
}

void UArsenalContentWidget::LoadAllCells()
{
	LoadCells(ArsenalWidgets, ArsenalCellsGrid, ArsenalsDataTable);
	LoadCells(ItemWidgets, ItemCellsGrid, ItemsDataTable);
}

void UArsenalContentWidget::LoadCells(TArray<UArsenalCellWidget*>& OutWidgets, UUniformGridPanel* Grid, UDataTable* DataTable)
{
	if (DataTable)
	{
		TArray<FName> RowNames = DataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FArsenalRow* Row = DataTable->FindRow<FArsenalRow>(RowName, "");
			UArsenalCellWidget* Widget = CreateWidget<UArsenalCellWidget>(GetWorld(), ArsenalCellWidgetClass);

			if (Widget)
			{
				Widget->SetValues(Row->ArsenalIcon, Row->Quantity);
				OutWidgets.Add(Widget);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 3; row++)
		{
			for (size_t col = 0; col < 3; col++)
			{
				auto Widget = OutWidgets[Index];
				Grid->AddChildToUniformGrid(Widget, row, col);
				Index++;
			}
		}
	}
}

void UArsenalContentWidget::SetupWidgetMapping()
{
	// Arsenals	// Items
	// 0 1 2	// 0 1 2
	// 3 4 5	// 3 4 5
	// 6 7 8	// 6 7 8

	SetupArsenalWidgetMapping();
	SetupItemWidgetMapping();

	// Arsenal to Items
	ArsenalWidgets[2]->SetMapOnRight(ItemWidgets[0]);
	ArsenalWidgets[5]->SetMapOnRight(ItemWidgets[3]);
	ArsenalWidgets[8]->SetMapOnRight(ItemWidgets[6]);

	// Items to Arsenal
	ItemWidgets[0]->SetMapOnLeft(ArsenalWidgets[2]);
	ItemWidgets[3]->SetMapOnLeft(ArsenalWidgets[5]);
	ItemWidgets[6]->SetMapOnLeft(ArsenalWidgets[8]);

	ArsenalWidgets[0]->SetHighlight();
	SelectedWidget = ArsenalWidgets[0];
}

void UArsenalContentWidget::SetupArsenalWidgetMapping()
{
	// Top Arsenals
	ArsenalWidgets[0]->SetMapOnRight(ArsenalWidgets[1]);
	ArsenalWidgets[1]->SetMapOnRight(ArsenalWidgets[2]);

	ArsenalWidgets[2]->SetMapOnLeft(ArsenalWidgets[1]);
	ArsenalWidgets[1]->SetMapOnLeft(ArsenalWidgets[0]);

	ArsenalWidgets[0]->SetMapBelow(ArsenalWidgets[3]);
	ArsenalWidgets[1]->SetMapBelow(ArsenalWidgets[4]);
	ArsenalWidgets[2]->SetMapBelow(ArsenalWidgets[5]);

	// Mid Arsenals
	ArsenalWidgets[3]->SetMapOnRight(ArsenalWidgets[4]);
	ArsenalWidgets[4]->SetMapOnRight(ArsenalWidgets[5]);

	ArsenalWidgets[5]->SetMapOnLeft(ArsenalWidgets[4]);
	ArsenalWidgets[4]->SetMapOnLeft(ArsenalWidgets[3]);

	ArsenalWidgets[3]->SetMapAbove(ArsenalWidgets[0]);
	ArsenalWidgets[4]->SetMapAbove(ArsenalWidgets[1]);
	ArsenalWidgets[5]->SetMapAbove(ArsenalWidgets[2]);

	ArsenalWidgets[3]->SetMapBelow(ArsenalWidgets[6]);
	ArsenalWidgets[4]->SetMapBelow(ArsenalWidgets[7]);
	ArsenalWidgets[5]->SetMapBelow(ArsenalWidgets[8]);

	// Bottom Arsenals
	ArsenalWidgets[6]->SetMapOnRight(ArsenalWidgets[7]);
	ArsenalWidgets[7]->SetMapOnRight(ArsenalWidgets[8]);

	ArsenalWidgets[8]->SetMapOnLeft(ArsenalWidgets[7]);
	ArsenalWidgets[7]->SetMapOnLeft(ArsenalWidgets[6]);

	ArsenalWidgets[6]->SetMapAbove(ArsenalWidgets[3]);
	ArsenalWidgets[7]->SetMapAbove(ArsenalWidgets[4]);
	ArsenalWidgets[8]->SetMapAbove(ArsenalWidgets[5]);
}

void UArsenalContentWidget::SetupItemWidgetMapping()
{
	// Top
	ItemWidgets[0]->SetMapOnRight(ItemWidgets[1]);
	ItemWidgets[1]->SetMapOnRight(ItemWidgets[2]);

	ItemWidgets[2]->SetMapOnLeft(ItemWidgets[1]);
	ItemWidgets[1]->SetMapOnLeft(ItemWidgets[0]);

	ItemWidgets[0]->SetMapBelow(ItemWidgets[3]);
	ItemWidgets[1]->SetMapBelow(ItemWidgets[4]);
	ItemWidgets[2]->SetMapBelow(ItemWidgets[5]);

	// Mid
	ItemWidgets[3]->SetMapOnRight(ItemWidgets[4]);
	ItemWidgets[4]->SetMapOnRight(ItemWidgets[5]);

	ItemWidgets[5]->SetMapOnLeft(ItemWidgets[4]);
	ItemWidgets[4]->SetMapOnLeft(ItemWidgets[3]);

	ItemWidgets[3]->SetMapAbove(ItemWidgets[0]);
	ItemWidgets[4]->SetMapAbove(ItemWidgets[1]);
	ItemWidgets[5]->SetMapAbove(ItemWidgets[2]);

	ItemWidgets[3]->SetMapBelow(ItemWidgets[6]);
	ItemWidgets[4]->SetMapBelow(ItemWidgets[7]);
	ItemWidgets[5]->SetMapBelow(ItemWidgets[8]);

	// Bottom
	ItemWidgets[6]->SetMapOnRight(ItemWidgets[7]);
	ItemWidgets[7]->SetMapOnRight(ItemWidgets[8]);

	ItemWidgets[8]->SetMapOnLeft(ItemWidgets[7]);
	ItemWidgets[7]->SetMapOnLeft(ItemWidgets[6]);

	ItemWidgets[6]->SetMapAbove(ItemWidgets[3]);
	ItemWidgets[7]->SetMapAbove(ItemWidgets[4]);
	ItemWidgets[8]->SetMapAbove(ItemWidgets[5]);
}

void UArsenalContentWidget::MoveSelectionUp()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveUp());
}

void UArsenalContentWidget::MoveSelectionDown()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveDown());
}

void UArsenalContentWidget::MoveSelectionLeft()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveLeft());
}

void UArsenalContentWidget::MoveSelectionRight()
{
	UpdateNewSelectedWidget(SelectedWidget->MoveRight());
}

void UArsenalContentWidget::UpdateNewSelectedWidget(UMappableWidget* MappableWidget)
{
	if (MappableWidget)
	{
		Cast<UArsenalCellWidget>(SelectedWidget)->SetHighlight(false);
		Cast<UArsenalCellWidget>(MappableWidget)->SetHighlight();
		SelectedWidget = MappableWidget;
	}
}
