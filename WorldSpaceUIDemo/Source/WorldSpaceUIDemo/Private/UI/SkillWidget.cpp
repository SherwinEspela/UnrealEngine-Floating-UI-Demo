// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SkillWidget.h"
#include "Components/TextBlock.h"
#include "Utility/ThemeManager.h"
#include "Components/Image.h"


void USkillWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ImageBG->SetBrushTintColor(FSlateColor(COLOR_BACKGROUND1));
	ImageBorder->SetBrushTintColor(FSlateColor(COLOR_BORDER_DEFAULT));
}

void USkillWidget::SetValues(UTexture2D* TextureSkillIcon, FString SkillName, int SkillLevel)
{
	if (TextureSkillIcon) ImageIcon->SetBrushFromTexture(TextureSkillIcon);
	TextSkillName->SetText(FText::FromString(SkillName).ToUpper());
	FString LevelValue = FString::Printf(TEXT("LEVEL %s"), *FString::FromInt(SkillLevel));
	TextLevel->SetText(FText::FromString(LevelValue));
}