// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/MappableWidget.h"
#include "UI/Interface/Highlightable.h"
#include "TargetWidget.generated.h"

class UImage;
class UTextBlock;
class USoundBase;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UTargetWidget : public UMappableWidget, public IHighlightable
{
	GENERATED_BODY()

public:
	UTargetWidget();

	void SetValues(FName RowNameValue, UTexture2D* TexturePhoto, FString TargetName, FString TargetId, int Difficulty, int AudioCount, bool IsLocated);
	void SetHighlight(bool ShoudHighlight = true);

public:
	FORCEINLINE void SetSoundFx(USoundBase* NewSound) { SfxSound = NewSound; }

protected:
	void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighlighted(bool Highlighted);
	
protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBorder;

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

	UPROPERTY(meta = (BindWidget))
	UImage* ImageIcon1;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageIcon2;

private:
	USoundBase* SfxSound;
};
