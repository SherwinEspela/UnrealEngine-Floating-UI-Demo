// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/Scifi/ScifiBarWidget.h"

void UScifiBarWidget::Play()
{
	IsPlaying = true;
	OnStartedPlaying();
}

void UScifiBarWidget::Stop()
{
	IsPlaying = false;
	OnStoppedPlaying();
}
