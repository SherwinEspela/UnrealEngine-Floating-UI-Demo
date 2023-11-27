// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Interface/Highlightable.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

void IHighlightable::SetHighlightOnBackgroundAndBorder(UImage* ImageBG, UImage* ImageBorder, bool ShoudHighlight)
{
	if (ShoudHighlight)
	{
		ThemeManager::SetCellHighlightColor(ImageBG);
		ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_HIGHLIGHT));
	}
	else {
		ThemeManager::SetCellBackgroundColor(ImageBG);
		ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
	}
}
