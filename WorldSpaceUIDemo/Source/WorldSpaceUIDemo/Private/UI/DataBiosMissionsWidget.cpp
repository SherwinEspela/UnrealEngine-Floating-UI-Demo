// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosMissionsWidget.h"
#include "UI/DataBios/MissionWidget.h"
#include "CustomStructs/MissionRow.h"
#include "Components/UniformGridPanel.h"

void UDataBiosMissionsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	LoadCells();
}

void UDataBiosMissionsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetupWidgetMapping();
}

void UDataBiosMissionsWidget::LoadCells()
{
	if (MissionsDataTable)
	{
		TArray<FName> RowNames = MissionsDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FMissionRow* Row = MissionsDataTable->FindRow<FMissionRow>(RowName, "");
			UMissionWidget* Widget = CreateWidget<UMissionWidget>(GetWorld(), MissionWidgetClass);

			if (Widget)
			{
				Widget->SetValues(RowName, Row->MissionIcon, Row->MissionName, Row->Difficulty, Row->IsCompleted);
				Widget->SetSoundFx(SfxMissionSelect);
				MissionWidgets.Add(Widget);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 2; row++)
		{
			for (size_t col = 0; col < 4; col++)
			{
				UMissionWidget* Widget = MissionWidgets[Index];
				CellsGrid->AddChildToUniformGrid(Widget, row, col);
				Index++;
			}
		}
	}
}

void UDataBiosMissionsWidget::SetupWidgetMapping()
{
	// 0 1 2 3
	// 4 5 6 7
	MissionWidgets[4]->SetMapAbove(MissionWidgets[0]);
	MissionWidgets[5]->SetMapAbove(MissionWidgets[1]);
	MissionWidgets[6]->SetMapAbove(MissionWidgets[2]);
	MissionWidgets[7]->SetMapAbove(MissionWidgets[3]);

	MissionWidgets[0]->SetMapOnRight(MissionWidgets[1]);
	MissionWidgets[1]->SetMapOnRight(MissionWidgets[2]);
	MissionWidgets[2]->SetMapOnRight(MissionWidgets[3]);

	MissionWidgets[4]->SetMapOnRight(MissionWidgets[5]);
	MissionWidgets[5]->SetMapOnRight(MissionWidgets[6]);
	MissionWidgets[6]->SetMapOnRight(MissionWidgets[7]);

	MissionWidgets[1]->SetMapOnLeft(MissionWidgets[0]);
	MissionWidgets[2]->SetMapOnLeft(MissionWidgets[1]);
	MissionWidgets[3]->SetMapOnLeft(MissionWidgets[2]);

	MissionWidgets[5]->SetMapOnLeft(MissionWidgets[4]);
	MissionWidgets[6]->SetMapOnLeft(MissionWidgets[5]);
	MissionWidgets[7]->SetMapOnLeft(MissionWidgets[6]);

	MissionWidgets[0]->SetMapBelow(MissionWidgets[4]);
	MissionWidgets[1]->SetMapBelow(MissionWidgets[5]);
	MissionWidgets[2]->SetMapBelow(MissionWidgets[6]);
	MissionWidgets[3]->SetMapBelow(MissionWidgets[7]);

	FirstElementWidget = MissionWidgets[0];
	SelectedWidget = MissionWidgets[0];
}

void UDataBiosMissionsWidget::SetMenuTab(UMappableWidget* Tab) const
{
	Super::SetMenuTab(Tab);

	MissionWidgets[0]->SetMapOnLeft(Tab);
	MissionWidgets[4]->SetMapOnLeft(Tab);

	MissionWidgets[0]->bIsExit = true;
	MissionWidgets[4]->bIsExit = true;
}

void UDataBiosMissionsWidget::SetHighlightOnFirstElementWidget()
{
	Super::SetHighlightOnFirstElementWidget();

	Cast<UMissionWidget>(FirstElementWidget)->SetHighlight();
	SelectedWidget = MissionWidgets[0];
}

void UDataBiosMissionsWidget::UpdateNewSelectedWidget(UMappableWidget* MappableWidget)
{
	Super::UpdateNewSelectedWidget(MappableWidget);

	if (MappableWidget)
	{
		Cast<UMissionWidget>(SelectedWidget)->SetHighlight(false);
		Cast<UMissionWidget>(MappableWidget)->SetHighlight();
		SelectedWidget = MappableWidget;
	}
}

void UDataBiosMissionsWidget::MoveSelectionLeft()
{
	if (SelectedWidget->bIsExit) Cast<UMissionWidget>(SelectedWidget)->SetHighlight(false);
	Super::MoveSelectionLeft();
}

FName UDataBiosMissionsWidget::GetRowNameFromSelectedWidget() const
{
	FName RowName = Cast<UMissionWidget>(SelectedWidget)->GetRowName();
	return RowName;
}

void UDataBiosMissionsWidget::Reset()
{
	if (SelectedWidget) Cast<UMissionWidget>(SelectedWidget)->SetHighlight(false);
}
