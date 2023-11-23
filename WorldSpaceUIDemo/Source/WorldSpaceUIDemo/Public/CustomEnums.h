// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EDataBiosSelectionRegion : uint8
{
	EDSR_Profile	UMETA(DisplayName = "Panel Profile"),
	EDSR_MainSkills	UMETA(DisplayName = "Panel Main Skills"),
	EDSR_Missions	UMETA(DisplayName = "Panel Missions"),
	EDSR_Targets	UMETA(DisplayName = "Panel Targets"),
	EDSR_SideMenu	UMETA(DisplayName = "Side Menu")
};
