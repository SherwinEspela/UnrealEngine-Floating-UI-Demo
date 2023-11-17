// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/DataBios/DataBiosGroupWidget.h"

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
}

void UMainMenuWidget::MoveSelectionUp()
{
	if (DataBiosGroup)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataBiosGroup AVAILABLE"));
		//DataBiosGroup->MoveSelectionUp();
	}
}

void UMainMenuWidget::MoveSelectionDown()
{
	if (DataBiosGroup)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataBiosGroup AVAILABLE"));
		//DataBiosGroup->MoveSelectionDown();
	}
}
