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
	TArray<UTargetWidget*> Widgets;
	if (TargetsDataTable)
	{
		if (bIsDebugging)
		{
			UE_LOG(LogTemp, Warning, TEXT("Targets data table available...."));
		}

		TArray<FName> RowNames = TargetsDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FTargetRow* Row = TargetsDataTable->FindRow<FTargetRow>(RowName, "");
			UTargetWidget* Widget = CreateWidget<UTargetWidget>(GetWorld(), TargetWidgetClass);

			if (Widget)
			{
				if (bIsDebugging)
				{
					UE_LOG(LogTemp, Warning, TEXT("Target Name ====== %s"), *Row->TargetName);
				}

				Widget->SetValues(Row->TexturePhoto, Row->TargetName, Row->TargetId, Row->Difficulty, Row->AudioCount, Row->IsLocated);
				Widgets.Add(Widget);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 2; row++)
		{
			for (size_t col = 0; col < 3; col++)
			{
				auto Widget = Widgets[Index];
				CellsGrid->AddChildToUniformGrid(Widget, row, col);
				Index++;
			}
		}
	}
}
