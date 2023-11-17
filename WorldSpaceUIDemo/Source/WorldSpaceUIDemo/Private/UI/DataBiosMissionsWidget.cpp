// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosMissionsWidget.h"
#include "UI/DataBios/MissionWidget.h"
#include "Components/UniformGridPanel.h"

void UDataBiosMissionsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UDataBiosMissionsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	LoadCells();
}

void UDataBiosMissionsWidget::LoadCells()
{
	TArray<UMissionWidget*> Widgets;
	if (MissionsDataTable)
	{
		TArray<FName> RowNames = MissionsDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FMissionRow* Row = MissionsDataTable->FindRow<FMissionRow>(RowName, "");
			UMissionWidget* Widget = CreateWidget<UMissionWidget>(GetWorld(), MissionWidgetClass);

			if (Widget)
			{
				Widget->SetValues(Row->MissionIcon, Row->MissionName, Row->Difficulty, Row->IsCompleted);
				Widgets.Add(Widget);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 2; row++)
		{
			for (size_t col = 0; col < 4; col++)
			{
				auto Widget = Widgets[Index];
				CellsGrid->AddChildToUniformGrid(Widget, row, col);
				Index++;
			}
		}
	}
}
