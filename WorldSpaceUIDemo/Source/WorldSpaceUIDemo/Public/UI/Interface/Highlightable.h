// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Highlightable.generated.h"

class UImage;

// This class does not need to be modified.
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

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetHighlight(bool ShoudHighlight = true);

	//UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;

	//UPROPERTY(meta = (BindWidget))
	UImage* ImageBorder;
};
