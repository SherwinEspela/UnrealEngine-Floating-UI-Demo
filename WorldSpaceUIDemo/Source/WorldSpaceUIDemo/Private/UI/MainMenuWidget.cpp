// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/DataBios/DataBiosGroupWidget.h"
#include "UI/Arsenal//ArsenalGroupWidget.h"
#include "UI/Abstract/NavigationBaseWidget.h"
#include "UI/BottomControls/BottomButtonWidget.h"
#include "UI/DataBios/Modal/ModalMissionWidget.h"
#include "UI/DataBiosMissionsWidget.h"
#include "CustomEnums.h"

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
	if (bIsDisplayingModal) return;
	CurrentNavigation->MoveSelectionUp();
}

void UMainMenuWidget::MoveSelectionDown()
{
	if (bIsDisplayingModal) return;
	CurrentNavigation->MoveSelectionDown();
}

void UMainMenuWidget::MoveSelectionLeft()
{
	if (bIsDisplayingModal) return;
	CurrentNavigation->MoveSelectionLeft();
}

void UMainMenuWidget::MoveSelectionRight()
{
	if (bIsDisplayingModal) return;
	CurrentNavigation->MoveSelectionRight();
}

void UMainMenuWidget::MoveTopBarSelectionLeft()
{
	if (bIsDisplayingModal) return;
	if (TopBar) TopBar->MoveSelectionLeft();
	CurrentNavigation = DataBiosGroup;
	OnDataBiosGroupSelected();
}

void UMainMenuWidget::MoveTopBarSelectionRight()
{
	if (bIsDisplayingModal) return;
	if (TopBar) TopBar->MoveSelectionRight();
	CurrentNavigation = ArsenalGroup;
	OnArsenalGroupSelected();
}

void UMainMenuWidget::OpenModal()
{
	auto SelectedTab = DataBiosGroup->GetCurrentSelectedTabType();

	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			//if (!MissionsDataTable) return;
			FName RowName = DataBiosGroup->GetRowNameFromSelectedWidget();
			FMissionRow* Row = MissionsDataTable->FindRow<FMissionRow>(RowName, "");
			ModalMission->SetValues(Row->MissionIcon, Row->MissionName, Row->Description, Row->MissionId, Row->IsCompleted, Row->Location, Row->Rewards);
			ModalMission->SetVisibility(ESlateVisibility::Visible);	
			break;
		//case EDataBiosSelectionRegion::EDSR_Targets:
		//	break;
		//default:
		//	break;
	}

	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
		case EDataBiosSelectionRegion::EDSR_Targets:
			BottomButtonA->OnButtonTapped();
			bIsDisplayingModal = true;
			break;
	}
}

void UMainMenuWidget::CloseModal()
{
	auto SelectedTab = DataBiosGroup->GetCurrentSelectedTabType();
	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			ModalMission->SetVisibility(ESlateVisibility::Hidden);
			break;
	/*	case EDataBiosSelectionRegion::EDSR_Targets:
			break;
		default:
			break;*/
	}

	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
		case EDataBiosSelectionRegion::EDSR_Targets:
			BottomButtonB->OnButtonTapped();
			bIsDisplayingModal = false;
			break;
	}
}
