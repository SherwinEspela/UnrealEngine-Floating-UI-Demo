// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TargetWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UTargetWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetValues(UTexture2D* TexturePhoto, FString TargetName, FString TargetId, int Difficulty, int AudioCount, bool IsLocated);
	
protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImagePhoto;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTargetName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTargetId;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDifficulty;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextAudioCount;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextStatus;
};
