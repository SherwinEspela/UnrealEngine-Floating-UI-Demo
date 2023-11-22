// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TopBarSideButtonWidget.generated.h"

class UTextblock;
class UImage;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UTopBarSideButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSideButtonTapped();
};
