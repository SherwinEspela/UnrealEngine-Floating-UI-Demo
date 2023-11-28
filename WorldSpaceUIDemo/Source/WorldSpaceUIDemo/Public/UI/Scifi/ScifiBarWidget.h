// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScifiBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UScifiBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Play();
	void Stop();

protected:
	UPROPERTY(BlueprintReadOnly)
	bool IsPlaying = false;

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartedPlaying();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStoppedPlaying();

};
