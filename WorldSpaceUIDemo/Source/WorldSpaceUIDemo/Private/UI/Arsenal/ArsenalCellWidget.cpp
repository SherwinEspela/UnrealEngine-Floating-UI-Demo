// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalCellWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Utility/ThemeManager.h"
#include "Kismet/GameplayStatics.h"

void UArsenalCellWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
	ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
}	

void UArsenalCellWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	ThemeManager::SetCellBackgroundColor(ImageBG, 0.9f);
	ThemeManager::SetBorderColor(ImageBorder);
	ThemeManager::SetTextToDefault(TextQuantity);

	OnHighlighted(false);
}

void UArsenalCellWidget::SetValues(UTexture2D* TextureArsenal, FString ArsenalNameValue, FString DescriptionValue, int Quantity)
{
	if (TextureArsenal) ImageArsenal->SetBrushFromTexture(TextureArsenal, true);

	ArsenalName = ArsenalNameValue;
	Description = DescriptionValue;

	FString QuantityValue = FString::FromInt(Quantity);
	TextQuantity->SetText(FText::FromString(QuantityValue));
}

void UArsenalCellWidget::SetHighlight(bool ShouldHighlight, bool WithSound)
{
	if (ShouldHighlight && SfxSound && WithSound) UGameplayStatics::PlaySound2D(this, SfxSound);
	SetHighlightOnBackgroundAndBorder(ImageBG, ImageBorder, ShouldHighlight);
	OnHighlighted(ShouldHighlight);
}

void UArsenalCellWidget::Reset()
{
	SetHighlightOnBackgroundAndBorder(ImageBG, ImageBorder, false);
	OnHighlighted(false);
}
