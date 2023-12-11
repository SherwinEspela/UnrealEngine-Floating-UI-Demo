// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BottomButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UBottomButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonTapped();
};
