// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Arsenal/ArsenalCellWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UArsenalCellWidget::SetValues(UTexture2D* TextureArsenal, int Quantity)
{
	if (TextureArsenal) ImageArsenal->SetBrushFromTexture(TextureArsenal, true);

	FString QuantityValue = FString::FromInt(Quantity);
	TextQuantity->SetText(FText::FromString(QuantityValue));
}
