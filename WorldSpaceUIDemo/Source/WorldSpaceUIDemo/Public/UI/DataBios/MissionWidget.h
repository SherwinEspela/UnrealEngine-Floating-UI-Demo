// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MissionWidget.generated.h"

class UImage;
class UTextBlock;
class UTexture2D;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UMissionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetValues(UTexture2D* TextureIcon, FString MissionName, int Difficulty, bool IsCompleted);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageIcon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextMissionName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDifficulty;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextStatus;
};