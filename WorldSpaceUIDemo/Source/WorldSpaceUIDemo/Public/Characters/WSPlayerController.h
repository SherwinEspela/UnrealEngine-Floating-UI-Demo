// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "WSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class APlayerCharacter;
class AHUDCameraActor;
class UMainMenuWidget;
class USoundBase;

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API AWSPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	/* Input Actions */
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputMappingContext* InputMappingContextPlayer;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionLookAround;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionReloadLevel;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionYButton;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionDPadUpButton;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionDPadDownButton;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionDPadLeftButton;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionDPadRightButton;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionL1Button;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionR1Button;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionAButton;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputAction* InputActionBButton;

protected:
	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedForward;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedRight;

	UPROPERTY(EditAnywhere)
	float CameraSwitchBlendTime = 0.5f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AHUDCameraActor> HUDCameraActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* SfxMainMenu;

private:
	void Move(const FInputActionValue& Value);
	void LookAround(const FInputActionValue& Value);
	void ReloadLevel();
	void MoveCompleted();
	void LookAroundStarted();
	void LookAroundCompleted();
	void ToggleCamera();
	void DPadUpTapped();
	void DPadDownTapped();
	void DPadLeftTapped();
	void DPadRightTapped();
	void ButtonL1Tapped();
	void ButtonR1Tapped();
	void ButtonATapped();
	void ButtonBTapped();

private:
	APlayerCharacter* PlayerCharacter;
	AHUDCameraActor* HUDCamera;

	bool IsRotatingRight = false;
	float CurrentRightAngleValue = 0.f;
	bool bCanResetControlOrientation = true;
	bool IsLookingAround = false;
	bool bIsViewingPlayerCamera = true;
	bool bIsDisplayingDataBios = true;
	bool bIsDisplayingModal = false;

private:
	UFUNCTION()
	void HandleModalDisplayChanged(bool IsDisplayingModal);
};
