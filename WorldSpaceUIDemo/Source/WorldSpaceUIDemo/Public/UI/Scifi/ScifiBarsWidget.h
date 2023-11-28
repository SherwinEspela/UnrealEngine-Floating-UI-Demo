// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScifiBarsWidget.generated.h"

class UScifiBarWidget;
class UHorizontalBox;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UScifiBarsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Play();
	void Stop();

protected:
	void NativePreConstruct() override;
	void NativeConstruct() override;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UScifiBarWidget> ScifiBarClass;

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* HorizontalBox;

	UPROPERTY(EditAnywhere)
	int NumberOfBars;

	UPROPERTY(EditAnywhere)
	float LeftPadding = 4.f;

	TArray<UScifiBarWidget*> Bars;
};
