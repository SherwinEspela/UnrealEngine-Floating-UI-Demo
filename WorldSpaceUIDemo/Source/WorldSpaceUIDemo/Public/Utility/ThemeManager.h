// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"

#define COLOR_BACKGROUND1 FColor::FromHex(TEXT("082928FF")) 
#define COLOR_HIGHLIGHT1 FColor::FromHex(TEXT("FF4021"))
#define COLOR_HIGHLIGHT2 FColor::FromHex(TEXT("DA1C00FF"))
#define COLOR_BORDER_DEFAULT FColor::FromHex(TEXT("32E798")) 
#define COLOR_BORDER_HIGHLIGHT FColor::FromHex(TEXT("fbdb17"))
#define COLOR_TOPBARTABTEXT_HIGHLIGHT1 FColor::FromHex(TEXT("E9D811"))
#define COLOR_TOPBARTABLINE_DEFAULT FColor::FromHex(TEXT("EE7519"))
#define COLOR_DARKGREEN FColor::FromHex(TEXT("0B1E1C"))
#define COLOR_CELL_BACKGROUND1 FColor::FromHex(TEXT("051611FF"))

// Text
#define COLOR_TEXT_DEFAULT1 FColor::FromHex(TEXT("00FFE7FF"))
#define COLOR_WHITE FColor::White
#define COLOR_RED FColor::Red

// Opacity
#define OPACITY1 0.5f
#define OPACITY2 0.75f

class UImage;
class UTextBlock;

/**
 *
 */
 class WORLDSPACEUIDEMO_API ThemeManager
 {
 public:
     ThemeManager();
     ~ThemeManager();

 public:
	 void static SetBackgroundColor(UImage* ImageBG);
	 void static SetBackgroundColor(UImage* ImageBG, FColor Color);
	 void static SetBackgroundColor(UImage* ImageBG, FColor Color, float Opacity);
	 void static SetCellBackgroundColor(UImage* ImageBG);
	 void static SetCellBackgroundColor(UImage* ImageBG, float Opacity);
	 void static SetCellHighlightColor(UImage* ImageBG);
	 void static SetTransparentBackgroundColor(UImage* ImageBG);
	 void static SetTransparentBackgroundColor(UImage* ImageBG, float Opacity);
	 void static SetTextToWhite(UTextBlock* Text);
	 void static SetTextToDefault(UTextBlock* Text);
	 void static SetTextColor(UTextBlock* Text, FColor Color);
	 void static SetTextArrayColor(TArray<UTextBlock*> TextArray, FColor Color);
	 void static SetAllTextToDefault(const UUserWidget& UserWidget);
	 void static SetBorderColor(UImage* ImageBG);
 };
