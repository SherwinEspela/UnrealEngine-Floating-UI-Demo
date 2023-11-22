// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/DataBios/DataBiosGroupWidget.h"
#include "UI/Arsenal//ArsenalGroupWidget.h"
#include "UI/Abstract/NavigationBaseWidget.h"
#include "UI/BottomControls/BottomButtonWidget.h"
#include "UI/DataBios/Modal/ModalMissionWidget.h"
#include "UI/DataBiosMissionsWidget.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (DotGrid)
	{
		DotGrid->SetMinDesiredSlotWidth(DotSize);
		DotGrid->SetMinDesiredSlotHeight(DotSize);

		for (size_t row = 0; row < DotCount; row++)
		{
			for (size_t col = 0; col < DotCount; col++)
			{
				UUserWidget* Dot = CreateWidget<UUserWidget>(GetWorld(), TilableDotClass);
				DotGrid->AddChildToUniformGrid(Dot, row, col);
			}
		}
	}

	ArsenalGroup->SetVisibility(ESlateVisibility::Hidden);
	CurrentNavigation = DataBiosGroup;
	CurrentNavigation->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::MoveSelectionUp()
{
	CurrentNavigation->MoveSelectionUp();
}

void UMainMenuWidget::MoveSelectionDown()
{
	CurrentNavigation->MoveSelectionDown();
}

void UMainMenuWidget::MoveSelectionLeft()
{
	CurrentNavigation->MoveSelectionLeft();
}

void UMainMenuWidget::MoveSelectionRight()
{
	CurrentNavigation->MoveSelectionRight();
}

void UMainMenuWidget::MoveTopBarSelectionLeft()
{
	if (TopBar) TopBar->MoveSelectionLeft();
	CurrentNavigation = DataBiosGroup;
	OnDataBiosGroupSelected();
}

void UMainMenuWidget::MoveTopBarSelectionRight()
{
	if (TopBar) TopBar->MoveSelectionRight();
	CurrentNavigation = ArsenalGroup;
	OnArsenalGroupSelected();
}

void UMainMenuWidget::OpenModal()
{
	if (!MissionsDataTable) return;
	FName RowName = DataBiosGroup->GetRowNameFromSelectedWidget();
	FMissionRow* Row = MissionsDataTable->FindRow<FMissionRow>(RowName, "");
	//UE_LOG(LogTemp, Warning, TEXT("Mission Name === %s"), *Row->MissionName);
	ModalMission->SetValues(Row->MissionIcon, Row->MissionName, Row->Description, Row->MissionId, Row->Location, Row->Rewards);
	ModalMission->SetVisibility(ESlateVisibility::Visible);
	BottomButtonA->OnButtonTapped();
}

void UMainMenuWidget::CloseModal()
{
	ModalMission->SetVisibility(ESlateVisibility::Hidden);
	BottomButtonB->OnButtonTapped();
}
