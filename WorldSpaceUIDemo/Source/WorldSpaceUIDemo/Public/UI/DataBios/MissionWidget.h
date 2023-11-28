// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/MappableWidget.h"
#include "UI/Interface/Highlightable.h"
#include "MissionWidget.generated.h"

class UImage;
class UTextBlock;
class UTexture2D;
class USoundBase;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UMissionWidget : public UMappableWidget, public IHighlightable
{
	GENERATED_BODY()

public:
	UMissionWidget();

	void SetValues(FName RowNameValue, UTexture2D* TextureIcon, FString MissionName, int Difficulty, bool IsCompleted);
	void SetHighlight(bool ShoudHighlight = true);

public:
	FORCEINLINE void SetSoundFx(USoundBase* NewSound) { SfxSound = NewSound; }

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighlighted(bool Highlighted);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageBorder;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageIcon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextMissionName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDifficulty;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextStatus;

private:
	USoundBase* SfxSound;
};
