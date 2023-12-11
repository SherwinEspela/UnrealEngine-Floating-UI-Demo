// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NavigationBaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UNavigationBaseWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void MoveSelectionUp();
	virtual void MoveSelectionDown();
	virtual void MoveSelectionLeft();
	virtual void MoveSelectionRight();
};
