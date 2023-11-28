// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/Modal/ModalTargetWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Utility/ThemeManager.h"
#include "UI/Scifi/ScifiBarsWidget.h"

void UModalTargetWidget::NativeConstruct()
{
	ThemeManager::SetCellBackgroundColor(ImageBG, 1.f);
	ThemeManager::SetAllTextToDefault(*this);
}

void UModalTargetWidget::SetValues(UTexture2D* TexturePhoto, FString TargetName, FString Description, FString Id, bool IsLocated, FString BirthDate, FString Location, int Rank)
{
	if (TexturePhoto) ImagePhoto->SetBrushFromTexture(TexturePhoto);
	TextTargetName->SetText(FText::FromString(TargetName));
	TextDescription->SetText(FText::FromString(Description).ToUpper());

	FString IdValue = FString::Printf(TEXT("ID-%s"), *Id);
	TextId->SetText(FText::FromString(IdValue).ToUpper());

	FString StatusValue = IsLocated ? TEXT("STATUS: Located") : TEXT("STATUS: Unknown");
	TextStatus->SetText(FText::FromString(StatusValue).ToUpper());
	
	TextDob->SetText(FText::FromString(BirthDate).ToUpper());
	
	TextLocation->SetText(FText::FromString(Location).ToUpper());
	
	FString RankValue = FString::Printf(TEXT("RANK: %s"), *FString::FromInt(Rank));
	TextRank->SetText(FText::FromString(RankValue));
}

void UModalTargetWidget::SetEnable(bool Enabled)
{
	if (Enabled)
	{
		ScifiBars->Play();
		OnEnabled(true);
	}
	else {
		ScifiBars->Stop();
		OnEnabled(false);
	}
}
