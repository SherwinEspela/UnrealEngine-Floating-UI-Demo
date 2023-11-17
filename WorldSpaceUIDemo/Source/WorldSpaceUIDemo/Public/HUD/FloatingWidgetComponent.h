// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "FloatingWidgetComponent.generated.h"

class UMainMenuWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UFloatingWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UFloatingWidgetComponent();

	virtual void BeginPlay() override;

public:
	void MoveSelectionUp();
	void MoveSelectionDown();

private:
	UMainMenuWidget* MainMenuWidget;
};
