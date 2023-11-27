// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/DataBios/Modal/ModalMissionWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Utility/ThemeManager.h"

void UModalMissionWidget::SetValues(UTexture2D* TextureMission, FString MissionName, FString Description, FString MissionId, bool IsCompleted, FString Location, FString Rewards)
{
	if (TextureMission) ImageMission->SetBrushFromTexture(TextureMission);

	TextMissionName->SetText(FText::FromString(MissionName.ToUpper()));
	TextDescription->SetText(FText::FromString(Description.ToUpper()));
	FString MissionIdValue = FString::Printf(TEXT("MISSION ID: %s"), *MissionId);
	TextMissionId->SetText(FText::FromString(MissionIdValue));
	FString StatusValue = FString::Printf(TEXT("STATUS: %s"), IsCompleted ? TEXT("Completed") : TEXT("Pending"));
	TextStatus->SetText(FText::FromString(StatusValue));
	TextLocation->SetText(FText::FromString(FString::Printf(TEXT("LOCATION: %s"), *Location)));
	TextRewards->SetText(FText::FromString(FString::Printf(TEXT("REWARDS: %s"), *Rewards)));
}
