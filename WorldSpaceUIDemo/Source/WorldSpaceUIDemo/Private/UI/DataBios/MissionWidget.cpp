// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/DataBios/MissionWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

UMissionWidget::UMissionWidget()
{
	SetSelectionRegion(EDataBiosSelectionRegion::EDSR_Missions);
}

void UMissionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ThemeManager::SetCellBackgroundColor(ImageBG, 0.9f);
	ThemeManager::SetBorderColor(ImageBorder);
	ThemeManager::SetAllTextToDefault(*this);
}

void UMissionWidget::SetValues(FName RowNameValue, UTexture2D* TextureIcon, FString MissionName, int Difficulty, bool IsCompleted)
{
	RowName = RowNameValue;

	if (TextureIcon) {
		ImageIcon->SetBrushFromTexture(TextureIcon);
	}

	TextMissionName->SetText(FText::FromString(MissionName.ToUpper()));
	FString DifficultyLevel = FString::Printf(TEXT("Difficulty: %i"), Difficulty);
	TextDifficulty->SetText(FText::FromString(DifficultyLevel.ToUpper()));

	FString Status = FString::Printf(TEXT("Status: %s"), IsCompleted ? TEXT("COMPLETED") : TEXT("PENDING"));
	TextStatus->SetText(FText::FromString(Status).ToUpper());
}

void UMissionWidget::SetHighlight(bool ShoudHighlight)
{
	SetHighlightOnBackgroundAndBorder(ImageBG, ImageBorder, ShoudHighlight);
	OnHighlighted(ShoudHighlight);
}
