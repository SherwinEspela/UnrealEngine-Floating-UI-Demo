// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosCommonWidget.generated.h"

class UUniformGridPanel;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosCommonWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* CellsGrid;

	UPROPERTY(EditAnywhere)
	bool bIsDebugging = false;

};
