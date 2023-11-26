// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Themable.generated.h"

class UImage;
class UTextBlock;

UINTERFACE(MinimalAPI)
class UThemable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WORLDSPACEUIDEMO_API IThemable
{
	GENERATED_BODY()

public:
	void SetBackgroundColor(UImage* ImageBG);
	void SetTransparentBackgroundColor(UImage* ImageBG);
	void SetTextToWhite(UTextBlock* Text);
	void SetTextArrayColor(TArray<UTextBlock*> TextArray, FColor Color);

};
