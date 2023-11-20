// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/MappableWidget.h"
#include "SideMenuTab.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API USideMenuTab : public UMappableWidget
{
	GENERATED_BODY()

public:	
	USideMenuTab();

	void SetHighlight(bool ShoudHighlight = true);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBorder;
};
