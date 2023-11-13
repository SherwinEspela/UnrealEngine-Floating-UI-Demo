// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillWidget.generated.h"

class UImage;
class UTextBlock;
class UTexture2D;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API USkillWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetValues(UTexture2D* TextureSkillIcon, FString SkillName, int SkillLevel);

protected:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageIcon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextSkillName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextLevel;
};
