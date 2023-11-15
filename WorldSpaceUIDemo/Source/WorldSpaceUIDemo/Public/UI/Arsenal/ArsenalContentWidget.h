// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArsenalContentWidget.generated.h"

class UUniformGridPanel;
class UArsenalCellWidget;

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

protected:
	void NativeConstruct() override;
	void NativePreConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* ArsenalCellsGrid;

	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* ItemCellsGrid;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UArsenalCellWidget> ArsenalCellWidgetClass;

private:
	void LoadAllCells();
	void LoadCells(UUniformGridPanel* Grid, UDataTable* DataTable);
};
