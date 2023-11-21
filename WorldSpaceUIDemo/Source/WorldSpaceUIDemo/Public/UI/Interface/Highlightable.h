// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Highlightable.generated.h"

class UImage;

UINTERFACE(MinimalAPI)
class UHighlightable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WORLDSPACEUIDEMO_API IHighlightable
{
	GENERATED_BODY()

public:
	virtual void SetHighlightOnBackgroundAndBorder(UImage* ImageBG, UImage* ImageBorder, bool ShoudHighlight = true);
};
