// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/MappableWidget.h"
#include "TopBarTabWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UTopBarTabWidget : public UMappableWidget
{
	GENERATED_BODY()

public:
	void SetHighlight(bool ShouldHighlight = true);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextTitle;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageTopLine;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBottomLine;

};
