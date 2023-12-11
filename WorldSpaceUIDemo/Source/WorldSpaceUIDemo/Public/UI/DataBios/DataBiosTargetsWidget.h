// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/DataBiosCommonWidget.h"
#include "DataBiosTargetsWidget.generated.h"

class UTargetWidget;

USTRUCT(BlueprintType)
struct FTargetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* TexturePhoto = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString TargetName = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Description = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString TargetId = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString BirthDate = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Location = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Difficulty = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Rank = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int AudioCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsLocated = false;
};

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UDataBiosTargetsWidget : public UDataBiosCommonWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UDataTable* TargetsDataTable;

public:
	virtual void SetHighlightOnFirstElementWidget() override;
	virtual void SetMenuTab(UMappableWidget* Tab) const override;
	virtual void MoveSelectionLeft() override;
	void Reset();

	FName GetRowNameFromSelectedWidget() const override;

protected:
	void NativeConstruct() override;
	void NativePreConstruct() override;
	virtual void UpdateNewSelectedWidget(UMappableWidget* MappableWidget) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UTargetWidget> TargetWidgetClass;

private:
	void LoadCells();
	void SetupWidgetMapping();

	TArray<UTargetWidget*> TargetWidgets;
};
