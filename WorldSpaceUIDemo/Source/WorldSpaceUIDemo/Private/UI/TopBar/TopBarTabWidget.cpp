// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/TopBar/TopBarTabWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

void UTopBarTabWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UTopBarTabWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ThemeManager::SetBackgroundColor(ImageTopLine, COLOR_TOPBARTABTEXT_HIGHLIGHT1);
	ThemeManager::SetBackgroundColor(ImageBottomLine, COLOR_TOPBARTABTEXT_HIGHLIGHT1);
	ThemeManager::SetTextToDefault(TextTitle);

	SetHighlight(false);
}

void UTopBarTabWidget::SetHighlight(bool ShouldHighlight)
{
	ESlateVisibility SlateVisibility = ShouldHighlight ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	ImageTopLine->SetVisibility(SlateVisibility);
	ImageBottomLine->SetVisibility(SlateVisibility);

	if (ShouldHighlight)
	{
		ThemeManager::SetTextColor(TextTitle, COLOR_TOPBARTABTEXT_HIGHLIGHT1);
	}
	else {
		ThemeManager::SetTextToDefault(TextTitle);
	}
}
