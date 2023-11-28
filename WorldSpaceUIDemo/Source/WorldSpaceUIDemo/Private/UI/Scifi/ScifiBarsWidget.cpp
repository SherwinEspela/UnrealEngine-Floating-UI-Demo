// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Scifi/ScifiBarsWidget.h"
#include "UI/Scifi/ScifiBarWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"

void UScifiBarsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (HorizontalBox && NumberOfBars > 0)
	{
		for (size_t i = 0; i < NumberOfBars; i++)
		{
			UScifiBarWidget* Bar = CreateWidget<UScifiBarWidget>(GetWorld(), ScifiBarClass);
			Bars.Add(Bar);
			UHorizontalBoxSlot* BoxSlot = HorizontalBox->AddChildToHorizontalBox(Bar);
			if (BoxSlot)
			{
				BoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
				BoxSlot->SetPadding(FMargin(LeftPadding, 0.f, 0.f, 0.f));
			}
		}
	}
}

void UScifiBarsWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UScifiBarsWidget::Play()
{
	if (Bars.IsEmpty()) return;

	for (UScifiBarWidget* Bar : Bars)
	{
		Bar->Play();
	}
}

void UScifiBarsWidget::Stop()
{
	if (Bars.IsEmpty()) return;

	for (UScifiBarWidget* Bar : Bars)
	{
		Bar->Stop();
	}
}
