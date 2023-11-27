// Copyright 2023 Sherwin Espela. All rights reserved.


#include "Utility/ThemeManager.h"
#include "Math/Color.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"

ThemeManager::ThemeManager()
{
}

ThemeManager::~ThemeManager()
{
}

void ThemeManager::SetBackgroundColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
}

void ThemeManager::SetCellBackgroundColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_CELL_BACKGROUND1));
}

void ThemeManager::SetCellBackgroundColor(UImage* ImageBG, float Opacity)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_CELL_BACKGROUND1));
	ImageBG->SetOpacity(Opacity);
}

void ThemeManager::SetCellHighlightColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_HIGHLIGHT2));
}

void ThemeManager::SetTransparentBackgroundColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_DARKGREEN));
	ImageBG->SetOpacity(OPACITY1);
}

void ThemeManager::SetTransparentBackgroundColor(UImage* ImageBG, float Opacity)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_DARKGREEN));
	ImageBG->SetOpacity(Opacity);
}

void ThemeManager::SetTextToWhite(UTextBlock* Text)
{
	Text->SetColorAndOpacity(FSlateColor(COLOR_WHITE));
}

void ThemeManager::SetTextToDefault(UTextBlock* Text)
{
	Text->SetColorAndOpacity(FSlateColor(COLOR_TEXT_DEFAULT1));
}

void ThemeManager::SetTextArrayColor(TArray<UTextBlock*> TextArray, FColor Color)
{
	for (auto Text : TextArray)
	{
		Text->SetColorAndOpacity(FSlateColor(Color));
	}
}

void ThemeManager::SetAllTextToDefault(const UUserWidget& UserWidget)
{
	TArray<UWidget*> Children;
	UserWidget.WidgetTree->GetAllWidgets(Children);

	for (auto Child : Children)
	{
		if (UTextBlock* TextBlock = Cast<UTextBlock>(Child))
		{
			TextBlock->SetColorAndOpacity(FSlateColor(COLOR_TEXT_DEFAULT1));
		}
	}
}

void ThemeManager::SetBorderColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
}
