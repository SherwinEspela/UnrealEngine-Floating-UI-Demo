// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/Modal/ModalTargetWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UModalTargetWidget::SetValues(UTexture2D* TexturePhoto, FString TargetName, FString Description, FString Id, bool IsLocated, FString BirthDate, FString Location, FString Rank, USoundBase* SFXAudio)
{
	if (TexturePhoto) ImagePhoto->SetBrushFromTexture(TexturePhoto);
	TextTargetName->SetText(FText::FromString(TargetName));
	TextDescription->SetText(FText::FromString(Description));
	FString IdValue = FString::Printf(TEXT("ID-%s"), *Id);
	TextId->SetText(FText::FromString(IdValue));
	FString StatusValue = IsLocated ? TEXT("Located") : TEXT("Unknown");
	TextStatus->SetText(FText::FromString(StatusValue));
	TextDob->SetText(FText::FromString(BirthDate));
	TextRank->SetText(FText::FromString(Rank));
	AudioLog = SFXAudio;
}
