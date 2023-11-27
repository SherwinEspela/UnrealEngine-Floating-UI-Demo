// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosProfileWidget.generated.h"

class UTextBlock;
class UImage;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosProfileWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text1Details;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text2Details;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text3Details;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;
};
