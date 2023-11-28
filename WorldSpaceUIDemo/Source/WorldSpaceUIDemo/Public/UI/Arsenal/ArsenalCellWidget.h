// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/MappableWidget.h"
#include "UI/Interface/Highlightable.h"
#include "ArsenalCellWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UArsenalCellWidget : public UMappableWidget, public IHighlightable
{
	GENERATED_BODY()

public:
	UArsenalCellWidget();

public:
	void SetValues(UTexture2D* TextureArsenal, FString ArsenalNameValue, FString DescriptionValue, int Quantity);
	void SetHighlight(bool ShoudHighlight = true);

public:
	FORCEINLINE FString GetArsenalName() const { return ArsenalName; }
	FORCEINLINE FString GetArsenalDescription() const { return Description; }

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighlighted(bool Highlighted);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBorder;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageArsenal;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextQuantity;

	FString ArsenalName;
	FString Description;
};
