// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"

#define COLOR_BACKGROUND1 FColor::FromHex(TEXT("051611")) 
#define COLOR_HIGHLIGHT1 FColor::FromHex(TEXT("FF4021"))
#define COLOR_BORDER_DEFAULT FColor::FromHex(TEXT("32E798")) 
#define COLOR_BORDER_HIGHLIGHT FColor::FromHex(TEXT("fbdb17"))
#define COLOR_TEXT_DEFAULT1 FColor::FromHex(TEXT("00FFF1FF"))
#define COLOR_WHITE FColor::White
#define COLOR_TOPBARTABTEXT_HIGHLIGHT1 FColor::FromHex(TEXT("E9D811"))
#define COLOR_TOPBARTABLINE_DEFAULT FColor::FromHex(TEXT("EE7519"))

/**
 * 
 */
class WORLDSPACEUIDEMO_API ThemeManager
{
public:
	ThemeManager();
	~ThemeManager();
};
