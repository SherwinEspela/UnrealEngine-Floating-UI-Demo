// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ModalTargetWidget.generated.h"

class UImage;
class UTextBlock;
class UTexture2D;
class USoundBase;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UModalTargetWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetValues(UTexture2D* TexturePhoto, FString TargetName, FString Description, FString Id, bool IsLocated,  FString BirthDate, FString Location, int Rank);

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;

	UPROPERTY(meta = (BindWidget))
	UImage* ImagePhoto;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTargetName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDescription;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextStatus;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextId;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDob;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextLocation;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextRank;
};
