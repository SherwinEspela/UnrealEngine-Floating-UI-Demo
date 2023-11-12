// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataBiosProfileWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosProfileWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text1Details;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text2Details;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text3Details;
};
