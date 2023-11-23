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
	void ShowMainMenu();
	void HideMainMenu();

	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionLeft();
	void MoveSelectionRight();
	void MoveTopBarSelectionLeft();
	void MoveTopBarSelectionRight();
	void OpenModal();
	void CloseModal();

private:
	UMainMenuWidget* MainMenuWidget;
};
