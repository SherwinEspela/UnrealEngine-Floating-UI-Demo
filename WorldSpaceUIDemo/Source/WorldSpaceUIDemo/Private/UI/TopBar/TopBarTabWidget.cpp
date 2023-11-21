// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/TopBar/TopBarTabWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Utility/ThemeManager.h"

void UTopBarTabWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	TextTitle->SetColorAndOpacity(FSlateColor(COLOR_TEXT_DEFAULT1));
	ImageTopLine->SetColorAndOpacity(FLinearColor(COLOR_TOPBARTABLINE_DEFAULT));
	ImageBottomLine->SetColorAndOpacity(FLinearColor(COLOR_TOPBARTABLINE_DEFAULT));

	SetHighlight(false);
}

void UTopBarTabWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TextTitle->SetColorAndOpacity(FSlateColor(COLOR_TEXT_DEFAULT1));
	ImageTopLine->SetColorAndOpacity(FLinearColor(COLOR_TOPBARTABLINE_DEFAULT));
	ImageBottomLine->SetColorAndOpacity(FLinearColor(COLOR_TOPBARTABLINE_DEFAULT));

	SetHighlight(false);
}

void UTopBarTabWidget::SetHighlight(bool ShouldHighlight)
{
	ESlateVisibility SlateVisibility = ShouldHighlight ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	ImageTopLine->SetVisibility(SlateVisibility);
	ImageBottomLine->SetVisibility(SlateVisibility);
	TextTitle->SetColorAndOpacity(FSlateColor(ShouldHighlight ? COLOR_TOPBARTABTEXT_HIGHLIGHT1 : COLOR_TEXT_DEFAULT1));
}
