// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/UniformGridPanel.h"

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

void UMainMenuWidget::SetSomething()
{
	GEngine->AddOnScreenDebugMessage(1, 15.f, FColor::Blue, TEXT("UMainMenuWidget::SetSomething"));
}