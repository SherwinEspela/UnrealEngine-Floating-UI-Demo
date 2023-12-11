// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/TopBar/TopBarWidget.h"
#include "MainMenuWidget.generated.h"

class UUniformGridPanel;
class UDataBiosGroupWidget;
class UTopBarWidget;
class UArsenalGroupWidget;
class UNavigationBaseWidget;
class UBottomButtonWidget;
class UModalMissionWidget;
class UModalTargetWidget;
class UScifiBarsWidget;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMainMenuModalDisplayChangedSignature, bool, IsDisplayingModal);

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void ShowMainMenu();
	void HideMainMenu();

	void MoveSelectionUp();
	void MoveSelectionDown();
	void MoveSelectionLeft();
	void MoveSelectionRight();
	void MoveTopBarSelectionLeft();
	void MoveTopBarSelectionRight();
	void OpenModal();
	void CloseModal();

	FOnMainMenuModalDisplayChangedSignature OnMainMenuModalDisplayChanged;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowMainMenu();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHideMainMenu();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShouldShowBottomButtons(bool ShouldShow);

protected:
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void Reset();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDataBiosGroupSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnArsenalGroupSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHideModal();

protected: // UI Elements
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUniformGridPanel* DotGrid;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> TilableDotClass;

	UPROPERTY(meta = (BindWidget))
	UDataBiosGroupWidget* DataBiosGroup;

	UPROPERTY(meta = (BindWidget))
	UArsenalGroupWidget* ArsenalGroup;

	UPROPERTY(meta = (BindWidget))
	UTopBarWidget* TopBar;

	UPROPERTY(meta = (BindWidget))
	UBottomButtonWidget* BottomButtonA;

	UPROPERTY(meta = (BindWidget))
	UBottomButtonWidget* BottomButtonB;

	UPROPERTY(meta = (BindWidget))
	UModalMissionWidget* ModalMission;

	UPROPERTY(meta = (BindWidget))
	UModalTargetWidget* ModalTarget;

	UPROPERTY(meta = (BindWidget))
	UScifiBarsWidget* ScifiBars;

	UPROPERTY(meta = (BindWidget))
	UScifiBarsWidget* ScifiBars2;

protected:
	UPROPERTY(EditAnywhere)
	UDataTable* MissionsDataTable;

	UPROPERTY(EditAnywhere)
	UDataTable* TargetsDataTable;

	UPROPERTY(EditAnywhere)
	int DotCount = 20;

	UPROPERTY(EditAnywhere)
	float DotSize = 100.f;
	
protected:
	UPROPERTY(EditAnywhere)
	USoundBase* SfxSwitchPanel;

	UPROPERTY(EditAnywhere)
	USoundBase* SfxModal;

private:
	UNavigationBaseWidget* CurrentNavigation;
	bool bIsDisplayingModal = false;
	bool bCanInteractWithModal = false;

private:
	UFUNCTION()
	void HandleSelectedRegionChanged(EDataBiosSelectionRegion SelectedRegion);

	EDataBiosSelectionRegion CurrentSelectedRegion;

	void SetBottomButtonsInteractable(bool IsInteractable = true);
	void ValidateModalsVisibility();
};
