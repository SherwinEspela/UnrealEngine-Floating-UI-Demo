// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/DataBiosTargetsWidget.h"
#include "UI/DataBios/TargetWidget.h"
#include "Components/UniformGridPanel.h"

void UDataBiosTargetsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	LoadCells();
}

void UDataBiosTargetsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetupWidgetMapping();
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
				Widget->SetValues(RowName, Row->TexturePhoto, Row->TargetName, Row->TargetId, Row->Difficulty, Row->AudioCount, Row->IsLocated);
				Widget->SetSoundFx(SfxMissionSelect);
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

	FirstElementWidget = TargetWidgets[0];
	SelectedWidget = TargetWidgets[0];
}

void UDataBiosTargetsWidget::SetHighlightOnFirstElementWidget()
{
	Super::SetHighlightOnFirstElementWidget();

	Cast<UTargetWidget>(FirstElementWidget)->SetHighlight();
	SelectedWidget = TargetWidgets[0];
}

void UDataBiosTargetsWidget::SetMenuTab(UMappableWidget* Tab) const
{
	Super::SetMenuTab(Tab);

	TargetWidgets[0]->SetMapOnLeft(Tab);
	TargetWidgets[3]->SetMapOnLeft(Tab);

	TargetWidgets[0]->bIsExit = true;
	TargetWidgets[3]->bIsExit = true;
}

void UDataBiosTargetsWidget::MoveSelectionLeft()
{
	if (SelectedWidget->bIsExit) Cast<UTargetWidget>(SelectedWidget)->SetHighlight(false);
	Super::MoveSelectionLeft();
}

void UDataBiosTargetsWidget::UpdateNewSelectedWidget(UMappableWidget* MappableWidget)
{
	Super::UpdateNewSelectedWidget(MappableWidget);

	if (MappableWidget)
	{
		Cast<UTargetWidget>(SelectedWidget)->SetHighlight(false);
		Cast<UTargetWidget>(MappableWidget)->SetHighlight();
		SelectedWidget = MappableWidget;
	}
}

FName UDataBiosTargetsWidget::GetRowNameFromSelectedWidget() const
{
	FName RowName = Cast<UTargetWidget>(SelectedWidget)->GetRowName();
	return RowName;
}

void UDataBiosTargetsWidget::Reset()
{
	if (SelectedWidget) Cast<UTargetWidget>(SelectedWidget)->SetHighlight(false);
}
