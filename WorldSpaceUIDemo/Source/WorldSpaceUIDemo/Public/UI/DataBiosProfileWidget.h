// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosProfileWidget.generated.h"

class UTextBlock;
class UImage;
class UScifiBarsWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosProfileWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void PlayScifiFX();
	void StopScifiFX();
	void Reset();

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

	UPROPERTY(meta = (BindWidget))
	UScifiBarsWidget* ScifiBars;
};
