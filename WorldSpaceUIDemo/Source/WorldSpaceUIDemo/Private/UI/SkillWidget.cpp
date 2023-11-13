// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SkillWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"


void USkillWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void USkillWidget::SetValues(UTexture2D* TextureSkillIcon, FString SkillName, int SkillLevel)
{
	if (TextureSkillIcon) ImageIcon->SetBrushFromTexture(TextureSkillIcon);
	TextSkillName->SetText(FText::FromString(SkillName));
	TextLevel->SetText(FText::FromString(FString::FromInt(SkillLevel)));
}