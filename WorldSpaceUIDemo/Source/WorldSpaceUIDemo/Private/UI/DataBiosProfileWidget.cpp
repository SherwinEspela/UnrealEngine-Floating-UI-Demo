// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosProfileWidget.h"
#include "Components/TextBlock.h"

void UDataBiosProfileWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Text1Details)
	{
		FString Paragraph1 = "Over 12 years of professional software development experience | ";
		FString Paragraph2 = "Well-versed in numerous programming languages including C++, C#, Swift, Python and JavaScript | ";
		FString Paragraph3 = "Developed applications and games for mobile devices and Windows PC using Unreal Engine, Unity 3D, React Native and XCode";
		FString Details = FString::Printf(TEXT("%s%s%s"), *Paragraph1, *Paragraph2, *Paragraph3);
		Text1Details->SetText(FText::FromString(Details.ToUpper()));
	}

	if (Text2Details)
	{
		FString Paragraph1 = "Over 2 years of knowledge and development experience using Unreal Engine | ";
		FString Paragraph2 = "Familiar with Unreal’s tools and systems such as Blueprint, Unreal Motion Graphics (UMG), and AI Navigation System and Behavior Trees";
		FString Details = FString::Printf(TEXT("%s%s"), *Paragraph1, *Paragraph2);
		Text2Details->SetText(FText::FromString(Details.ToUpper()));
	}

	if (Text3Details)
	{
		FString Paragraph1 = "Over 15 years of experience in 3D / 2D Media Arts in a high-end digital broadcast/design environment | ";
		FString Paragraph2 = "Proficient in Autodesk Maya, Blender, Adobe Photoshop and other tools for media art creation";
		FString Details = FString::Printf(TEXT("%s%s"), *Paragraph1, *Paragraph2);
		Text3Details->SetText(FText::FromString(Details.ToUpper()));
	}
}
