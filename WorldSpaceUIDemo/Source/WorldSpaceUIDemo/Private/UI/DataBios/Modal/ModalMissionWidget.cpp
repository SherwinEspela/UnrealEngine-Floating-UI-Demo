// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/Modal/ModalMissionWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UModalMissionWidget::SetValues(UTexture2D* TextureMission, FString MissionName, FString Description, FString MissionId, FString Location, TArray<FString> Rewards)
{
	if (TextureMission)
	{
		ImageMission->SetBrushFromTexture(TextureMission);
	}

	TextMissionName->SetText(FText::FromString(MissionName.ToUpper()));
	TextDescription->SetText(FText::FromString(Description.ToUpper()));
	FString MissionIdValue = FString::Printf(TEXT("ID-%S"), *MissionId);
	TextMissionId->SetText(FText::FromString(MissionIdValue));
	TextLocation->SetText(FText::FromString(Location));

	FString RewardsValue;
	for (FString Reward : Rewards)
	{
		RewardsValue += FString::Printf(TEXT(", "), *Reward);
	}
	TextRewards->SetText(FText::FromString(RewardsValue));
}
