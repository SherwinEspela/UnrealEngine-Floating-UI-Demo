// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/TopBar/TopBarWidget.h"
#include "MainMenuWidget.generated.h"

class UUniformGridPanel;
class UDataBiosGroupWidget;
class UTopBarWidget;
class UArsenalGroupWidget;
class UNavigationBaseWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionLeft();
	void MoveSelectionRight();
	void MoveTopBarSelectionLeft();
	void MoveTopBarSelectionRight();

protected:
	void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUniformGridPanel* DotGrid;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> TilableDotClass;

	UPROPERTY(meta = (BindWidget))
	UDataBiosGroupWidget* DataBiosGroup;

	UPROPERTY(meta = (BindWidget))
	UArsenalGroupWidget* ArsenalGroup;

	UPROPERTY(meta = (BindWidget))
	UTopBarWidget* TopBar;

	UPROPERTY(EditAnywhere)
	int DotCount = 20;

	UPROPERTY(EditAnywhere)
	float DotSize = 100.f;

private:
	UNavigationBaseWidget* CurrentNavigation;
};
