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

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedForward;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedRight;

	UPROPERTY(EditAnywhere)
	float CameraSwitchBlendTime = 0.5f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AHUDCameraActor> HUDCameraActorClass;

private:
	void Move(const FInputActionValue& Value);
	void LookAround(const FInputActionValue& Value);
	void ReloadLevel();
	void MoveCompleted();
	void LookAroundStarted();
	void LookAroundCompleted();
	void ToggleCamera();

	APlayerCharacter* PlayerCharacter;
	AHUDCameraActor* HUDCamera;

	bool IsRotatingRight = false;
	float CurrentRightAngleValue = 0.f;
	bool bCanResetControlOrientation = true;
	bool IsLookingAround = false;
	bool bIsViewingPlayerCamera = true;
};
