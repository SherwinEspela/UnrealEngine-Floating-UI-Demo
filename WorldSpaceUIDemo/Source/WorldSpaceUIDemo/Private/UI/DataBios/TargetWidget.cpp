// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/TargetWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

UTargetWidget::UTargetWidget()
{
	SetSelectionRegion(EDataBiosSelectionRegion::EDSR_Targets);
}

void UTargetWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ThemeManager::SetCellBackgroundColor(ImageBG, 0.9f);
	ThemeManager::SetBorderColor(ImageBorder);
	ThemeManager::SetAllTextToDefault(*this);
}

void UTargetWidget::SetValues(FName RowNameValue, UTexture2D* TexturePhoto, FString TargetName, FString TargetId, int Difficulty, int AudioCount, bool IsLocated)
{
	RowName = RowNameValue;

	if (TexturePhoto)
	{
		ImagePhoto->SetBrushFromTexture(TexturePhoto);
	}

	TextTargetName->SetText(FText::FromString(TargetName.ToUpper()));
	TextTargetId->SetText(FText::FromString(TargetId.ToUpper()));
	FString DifficultyValue = FString::Printf(TEXT("%s/10"), *FString::FromInt(Difficulty));
	TextDifficulty->SetText(FText::FromString(DifficultyValue));
	FString AudioCountValue = FString::Printf(TEXT("%s/4"), *FString::FromInt(AudioCount));
	TextAudioCount->SetText(FText::FromString(AudioCountValue));
	FString StatusValue = IsLocated ? TEXT("Located") : TEXT("Unknown");
	TextStatus->SetText(FText::FromString(FString::Printf(TEXT("STATUS: %s"), *StatusValue.ToUpper())));
}

void UTargetWidget::SetHighlight(bool ShoudHighlight)
{
	SetHighlightOnBackgroundAndBorder(ImageBG, ImageBorder, ShoudHighlight);
}
