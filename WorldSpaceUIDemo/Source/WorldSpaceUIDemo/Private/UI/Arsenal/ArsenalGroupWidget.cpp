// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalGroupWidget.h"
#include "UI/Arsenal/ArsenalContentWidget.h"
#include "Components/TextBlock.h"

void UArsenalGroupWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ArsenalContents->OnArsenalWidgetSelected.AddDynamic(this, &UArsenalGroupWidget::HandleArsenalWidgetSelected);
}

void UArsenalGroupWidget::MoveSelectionUp()
{
	ArsenalContents->MoveSelectionUp();
}

void UArsenalGroupWidget::MoveSelectionDown()
{
	ArsenalContents->MoveSelectionDown();
}

void UArsenalGroupWidget::MoveSelectionLeft()
{
	ArsenalContents->MoveSelectionLeft();
}

void UArsenalGroupWidget::MoveSelectionRight()
{
	ArsenalContents->MoveSelectionRight();
}

void UArsenalGroupWidget::HandleArsenalWidgetSelected(FString ArsenalName, FString Description)
{
	//UE_LOG(LogTemp, Warning, TEXT("Arsenal Name = %s"), *ArsenalName);
	TextArsenalName->SetText(FText::FromString(ArsenalName));
	TextDescription->SetText(FText::FromString(Description));
}