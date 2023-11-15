// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArsenalCellWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UArsenalCellWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetValues(UTexture2D* TextureArsenal, int Quantity);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageArsenal;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextQuantity;
};
