// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/DataBiosTargetsWidget.h"
#include "UI/DataBios/TargetWidget.h"
#include "Components/UniformGridPanel.h"

void UDataBiosTargetsWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UDataBiosTargetsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	LoadCells();
}

void UDataBiosTargetsWidget::LoadCells()
{
	if (TargetsDataTable)
	{
		TArray<FName> RowNames = TargetsDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FTargetRow* Row = TargetsDataTable->FindRow<FTargetRow>(RowName, "");
			UTargetWidget* Widget = CreateWidget<UTargetWidget>(GetWorld(), TargetWidgetClass);

			if (Widget)
			{
				Widget->SetValues(Row->TexturePhoto, Row->TargetName, Row->TargetId, Row->Difficulty, Row->AudioCount, Row->IsLocated);
				TargetWidgets.Add(Widget);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 2; row++)
		{
			for (size_t col = 0; col < 3; col++)
			{
				auto Widget = TargetWidgets[Index];
				CellsGrid->AddChildToUniformGrid(Widget, row, col);
				Index++;
			}
		}
	}
}

void UDataBiosTargetsWidget::SetupWidgetMapping()
{
	// 0 1 2
	// 3 4 5
	TargetWidgets[0]->SetMapOnRight(TargetWidgets[1]);
	TargetWidgets[1]->SetMapOnRight(TargetWidgets[2]);

	TargetWidgets[3]->SetMapOnRight(TargetWidgets[4]);
	TargetWidgets[4]->SetMapOnRight(TargetWidgets[5]);

	TargetWidgets[0]->SetMapBelow(TargetWidgets[3]);
	TargetWidgets[1]->SetMapBelow(TargetWidgets[4]);
	TargetWidgets[2]->SetMapBelow(TargetWidgets[5]);

	TargetWidgets[1]->SetMapOnLeft(TargetWidgets[0]);
	TargetWidgets[2]->SetMapOnLeft(TargetWidgets[1]);

	TargetWidgets[4]->SetMapOnLeft(TargetWidgets[3]);
	TargetWidgets[5]->SetMapOnLeft(TargetWidgets[4]);

	TargetWidgets[3]->SetMapAbove(TargetWidgets[0]);
	TargetWidgets[4]->SetMapAbove(TargetWidgets[1]);
	TargetWidgets[5]->SetMapAbove(TargetWidgets[2]);
}

void UDataBiosTargetsWidget::MoveSelectionUp()
{
}

void UDataBiosTargetsWidget::MoveSelectionDown()
{
}

void UDataBiosTargetsWidget::MoveSelectionLeft()
{
}

void UDataBiosTargetsWidget::MoveSelectionRight()
{
}
