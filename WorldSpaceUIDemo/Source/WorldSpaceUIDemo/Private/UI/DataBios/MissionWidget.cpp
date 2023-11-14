// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/DataBios/MissionWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UMissionWidget::SetValues(UTexture2D* TextureIcon, FString MissionName, int Difficulty, bool IsCompleted)
{
	if (TextureIcon) {
		ImageIcon->SetBrushFromTexture(TextureIcon);
	}

	TextMissionName->SetText(FText::FromString(MissionName.ToUpper()));
	FString DifficultyLevel = FString::Printf(TEXT("Difficulty: %i"), Difficulty);
	TextDifficulty->SetText(FText::FromString(DifficultyLevel.ToUpper()));

	FString Status = FString::Printf(TEXT("Status: %s"), IsCompleted ? TEXT("Completed") : TEXT("Pending"));
	TextStatus->SetText(FText::FromString(Status.ToUpper()));
}
