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
	void SetValues(UTexture2D* TexturePhoto, FString TargetName, FString Description, FString Id, bool IsLocated,  FString BirthDate, FString Location, FString Rank, USoundBase* SFXAudio);

protected:
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

	UPROPERTY(EditAnywhere)
	USoundBase* AudioLog;
};
