// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Interface/Highlightable.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

void IHighlightable::SetHighlightOnBackgroundAndBorder(UImage* ImageBG, UImage* ImageBorder, bool ShoudHighlight)
{
	if (ShoudHighlight)
	{
		ImageBG->SetBrushTintColor(FSlateColor(COLOR_HIGHLIGHT1));
		ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_HIGHLIGHT));
	}
	else {
		ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
		ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
	}
}
