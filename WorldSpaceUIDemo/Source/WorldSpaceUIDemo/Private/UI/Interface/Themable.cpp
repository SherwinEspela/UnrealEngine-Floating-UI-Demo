// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Interface/Themable.h"
#include "Utility/ThemeManager.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void IThemable::SetBackgroundColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
}

void IThemable::SetTransparentBackgroundColor(UImage* ImageBG)
{
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_DARKGREEN));
	ImageBG->SetOpacity(OPACITY1);
}

void IThemable::SetTextToWhite(UTextBlock* Text)
{
	Text->SetColorAndOpacity(FSlateColor(COLOR_WHITE));
}

void IThemable::SetTextArrayColor(TArray<UTextBlock*> TextArray, FColor Color)
{
	for (auto Text : TextArray)
	{
		Text->SetColorAndOpacity(FSlateColor(Color));
	}
}
