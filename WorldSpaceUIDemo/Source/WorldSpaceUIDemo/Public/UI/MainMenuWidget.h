// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UUniformGridPanel;
class UDataBiosGroupWidget;

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

protected:
	void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUniformGridPanel* DotGrid;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> TilableDotClass;

	UPROPERTY(meta = (BindWidget))
	UDataBiosGroupWidget* DataBiosGroup;

	UPROPERTY(EditAnywhere)
	int DotCount = 20;

	UPROPERTY(EditAnywhere)
	float DotSize = 100.f;
};
