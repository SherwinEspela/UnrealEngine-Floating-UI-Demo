// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/DataBios/DataBiosGroupWidget.h"
#include "UI/Arsenal//ArsenalGroupWidget.h"
#include "UI/Abstract/NavigationBaseWidget.h"
#include "UI/BottomControls/BottomButtonWidget.h"
#include "UI/DataBios/Modal/ModalMissionWidget.h"
#include "UI/DataBios/Modal/ModalTargetWidget.h"
#include "UI/DataBiosMissionsWidget.h"
#include "UI/DataBios/DataBiosTargetsWidget.h"
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

	DataBiosGroup->OnSelectedRegionChanged.AddDynamic(this, &UMainMenuWidget::HandleSelectedRegionChanged);
	Reset();
	ArsenalGroup->SetVisibility(ESlateVisibility::Hidden);
	CurrentNavigation->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::ShowMainMenu()
{
	OnShowMainMenu();
}

void UMainMenuWidget::HideMainMenu()
{
	OnHideMainMenu();
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
	ValidateModalsVisibility();
	OnDataBiosGroupSelected();
}

void UMainMenuWidget::MoveTopBarSelectionRight()
{
	if (bIsDisplayingModal) return;
	if (TopBar) TopBar->MoveSelectionRight();
	CurrentNavigation = ArsenalGroup;
	SetBottomButtonsInteractable(false);
	OnArsenalGroupSelected();
}

void UMainMenuWidget::OpenModal()
{
	if (!bCanInteractWithModal) return;
	if (bIsDisplayingModal) return;

	EDataBiosSelectionRegion SelectedTab = DataBiosGroup->GetCurrentSelectedTabType();
	FName RowName = DataBiosGroup->GetRowNameFromSelectedWidget();

	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
		{
			if (!MissionsDataTable) return;
			FMissionRow* Row = MissionsDataTable->FindRow<FMissionRow>(RowName, "");
			if (!Row) return;
			ModalMission->SetValues(
				Row->MissionIcon, 
				Row->MissionName, 
				Row->Description, 
				Row->MissionId, 
				Row->IsCompleted, 
				Row->Location, 
				Row->Rewards
			);
			ModalMission->SetVisibility(ESlateVisibility::Visible);
		}
			break;
		case EDataBiosSelectionRegion::EDSR_Targets:
		{
			if (!TargetsDataTable) return;
			FTargetRow* TargetRow = TargetsDataTable->FindRow<FTargetRow>(RowName, "");
			if (!TargetRow) return;
			ModalTarget->SetValues(
				TargetRow->TexturePhoto, 
				TargetRow->TargetName, 
				TargetRow->Description, 
				TargetRow->TargetId, 
				TargetRow->IsLocated, 
				TargetRow->BirthDate, 
				TargetRow->Location, 
				TargetRow->Rank
			);
			ModalTarget->SetVisibility(ESlateVisibility::Visible);
		}
			break;
		default:
			break;
	}

	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
		case EDataBiosSelectionRegion::EDSR_Targets:
			BottomButtonA->OnButtonTapped();
			bIsDisplayingModal = true;
			OnMainMenuModalDisplayChanged.Broadcast(bIsDisplayingModal);
			break;
	}
}

void UMainMenuWidget::CloseModal()
{
	if (!bCanInteractWithModal) return;
	if (!bIsDisplayingModal) return;

	EDataBiosSelectionRegion SelectedTab = DataBiosGroup->GetCurrentSelectedTabType();
	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
			ModalMission->SetVisibility(ESlateVisibility::Hidden);
			break;
		case EDataBiosSelectionRegion::EDSR_Targets:
			ModalTarget->SetVisibility(ESlateVisibility::Hidden);
			break;
		default:
			break;
	}

	switch (SelectedTab)
	{
		case EDataBiosSelectionRegion::EDSR_Missions:
		case EDataBiosSelectionRegion::EDSR_Targets:
			BottomButtonB->OnButtonTapped();
			bIsDisplayingModal = false;
			OnMainMenuModalDisplayChanged.Broadcast(bIsDisplayingModal);
			break;
	}
}

void UMainMenuWidget::HandleSelectedRegionChanged(EDataBiosSelectionRegion SelectedRegion)
{
	CurrentSelectedRegion = SelectedRegion;
	ValidateModalsVisibility();
}

void UMainMenuWidget::SetBottomButtonsInteractable(bool IsInteractable)
{
	bCanInteractWithModal = IsInteractable;
	OnShouldShowBottomButtons(IsInteractable);
}

void UMainMenuWidget::ValidateModalsVisibility()
{
	switch (CurrentSelectedRegion)
	{
	case EDataBiosSelectionRegion::EDSR_Missions:
	case EDataBiosSelectionRegion::EDSR_Targets:
		SetBottomButtonsInteractable();
		break;
	default:
		SetBottomButtonsInteractable(false);
		break;
	}
}

void UMainMenuWidget::Reset()
{
	DataBiosGroup->Reset();
	ArsenalGroup->Reset();
	TopBar->Reset();

	CurrentSelectedRegion = EDataBiosSelectionRegion::EDSR_SideMenu;
	CurrentNavigation = DataBiosGroup;

	bCanInteractWithModal = false;
	bIsDisplayingModal = false;
}
