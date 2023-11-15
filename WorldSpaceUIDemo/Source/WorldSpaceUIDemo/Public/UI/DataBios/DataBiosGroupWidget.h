// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosGroupWidget.generated.h"

class UTextBlock;
class UDataBiosWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosGroupWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UDataBiosWidget* DataBios;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTitle;

};
