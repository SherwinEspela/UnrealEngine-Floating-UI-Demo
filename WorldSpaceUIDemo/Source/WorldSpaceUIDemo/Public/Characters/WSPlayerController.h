// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "WSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class APlayerCharacter;

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

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedForward;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedRight;

private:
	void Move(const FInputActionValue& Value);
	void LookAround(const FInputActionValue& Value);
	void ReloadLevel();

	APlayerCharacter* PlayerCharacter;

	bool IsRotatingRight = false;
	float CurrentRightAngleValue = 0.f;
};
