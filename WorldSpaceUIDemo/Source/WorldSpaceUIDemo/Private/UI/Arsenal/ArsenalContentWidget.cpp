// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalContentWidget.h"
#include "UI/Arsenal/ArsenalCellWidget.h"
#include "Components/UniformGridPanel.h"

void UArsenalContentWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UArsenalContentWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	LoadAllCells();
}

void UArsenalContentWidget::LoadAllCells()
{
	LoadCells(ArsenalCellsGrid, ArsenalsDataTable);
	LoadCells(ItemCellsGrid, ItemsDataTable);
}

void UArsenalContentWidget::LoadCells(UUniformGridPanel* Grid, UDataTable* DataTable)
{
	TArray<UArsenalCellWidget*> Widgets;
	if (DataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Arsenals data table available...."));

		TArray<FName> RowNames = DataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FArsenalRow* Row = DataTable->FindRow<FArsenalRow>(RowName, "");
			UArsenalCellWidget* Widget = CreateWidget<UArsenalCellWidget>(GetWorld(), ArsenalCellWidgetClass);

			if (Widget)
			{
				UE_LOG(LogTemp, Warning, TEXT("Arsenal Name ====== %s"), *Row->ArsenalName);

				Widget->SetValues(Row->ArsenalIcon, Row->Quantity);
				Widgets.Add(Widget);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 3; row++)
		{
			for (size_t col = 0; col < 3; col++)
			{
				auto Widget = Widgets[Index];
				Grid->AddChildToUniformGrid(Widget, row, col);
				Index++;
			}
		}
	}
}
