// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TopButtonWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UTopButtonWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextTitle;
};
