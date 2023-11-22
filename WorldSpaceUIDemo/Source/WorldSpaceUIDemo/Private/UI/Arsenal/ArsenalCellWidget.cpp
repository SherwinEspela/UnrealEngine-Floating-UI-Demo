// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalCellWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Utility/ThemeManager.h"

UArsenalCellWidget::UArsenalCellWidget()
{

}

void UArsenalCellWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
	ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
}	

void UArsenalCellWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
	ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
}

void UArsenalCellWidget::SetValues(UTexture2D* TextureArsenal, FString ArsenalNameValue, FString DescriptionValue, int Quantity)
{
	if (TextureArsenal) ImageArsenal->SetBrushFromTexture(TextureArsenal, true);

	ArsenalName = ArsenalNameValue;
	Description = DescriptionValue;

	FString QuantityValue = FString::FromInt(Quantity);
	TextQuantity->SetText(FText::FromString(QuantityValue));
}

void UArsenalCellWidget::SetHighlight(bool ShoudHighlight)
{
	SetHighlightOnBackgroundAndBorder(ImageBG, ImageBorder, ShoudHighlight);
}
