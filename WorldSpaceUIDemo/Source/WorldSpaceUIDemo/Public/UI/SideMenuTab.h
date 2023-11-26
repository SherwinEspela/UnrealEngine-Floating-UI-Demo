// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/MappableWidget.h"
#include "UI/Interface/Themable.h"
#include "SideMenuTab.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API USideMenuTab : public UMappableWidget, public IThemable
{
	GENERATED_BODY()

public:	
	USideMenuTab();

	void SetHighlight(bool ShoudHighlight = true);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBorder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextTitle;
};
