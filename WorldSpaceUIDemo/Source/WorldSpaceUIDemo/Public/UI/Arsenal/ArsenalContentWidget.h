// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArsenalContentWidget.generated.h"

class UUniformGridPanel;
class UArsenalCellWidget;
class UMappableWidget;

USTRUCT(BlueprintType)
struct FArsenalRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* ArsenalIcon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ArsenalName = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Description = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Quantity = 1;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArsenalWidgetSelectedSignature, FString, ArsenalName, FString, Description);

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UArsenalContentWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UDataTable* ArsenalsDataTable;
	
	UPROPERTY(EditAnywhere)
	UDataTable* ItemsDataTable;

	FOnArsenalWidgetSelectedSignature OnArsenalWidgetSelected;

public:
	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionRight();
	void MoveSelectionLeft();
	void Reset();

	FString GetSelectedArsenalName() const;
	FString GetSelectedArsenalDescription() const;

protected:
	void NativeConstruct() override;
	void NativePreConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* ArsenalCellsGrid;

	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* ItemCellsGrid;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UArsenalCellWidget> ArsenalCellWidgetClass;

	UPROPERTY(EditAnywhere)
	USoundBase* SfxArsenalSelect;

private:
	TArray<UArsenalCellWidget*> ArsenalWidgets;
	TArray<UArsenalCellWidget*> ItemWidgets;
	UMappableWidget* SelectedWidget;

private:
	void LoadAllCells();
	void LoadCells(TArray<UArsenalCellWidget*>& OutWidgets, UUniformGridPanel* Grid, UDataTable* DataTable);
	void SetupWidgetMapping();
	void SetupArsenalWidgetMapping();
	void SetupItemWidgetMapping();
	void UpdateNewSelectedWidget(UMappableWidget* MappableWidget);

};
