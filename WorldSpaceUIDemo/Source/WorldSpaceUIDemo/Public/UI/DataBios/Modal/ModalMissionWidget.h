// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ModalMissionWidget.generated.h"

class UImage;
class UTextBlock;
class UScifiBarsWidget;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UModalMissionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetValues(UTexture2D* TextureMission, FString MissionName, FString Description, FString MissionId, bool IsCompleted, FString Location, FString Rewards);
	void SetEnable(bool Enabled);

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetHidden();

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnabled(bool Enabled);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ImageBG;

	UPROPERTY(meta = (BindWidget))
	UImage* ImageMission;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextMissionName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDescription;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextMissionId;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextStatus;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextLocation;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextRewards;

	UPROPERTY(meta = (BindWidget))
	UScifiBarsWidget* ScifiBars;
};
