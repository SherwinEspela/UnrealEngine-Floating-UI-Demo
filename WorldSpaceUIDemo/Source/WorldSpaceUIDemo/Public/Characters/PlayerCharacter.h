// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
class AHUDCameraActor;
class UMainMenuWidget;

UCLASS()
class WORLDSPACEUIDEMO_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;

	void TurnRight(bool Right = true);
	void SetOrientRotationToMovement(bool Value);
	UMainMenuWidget* GetMainMenuWidget();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Display)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Display)
	UCameraComponent* Camera;

public:
	FORCEINLINE void SetMoveSpeedForward(float Value) { MoveSpeedForward = Value; }
	FORCEINLINE void SetMoveSpeedRight(float Value) { MoveSpeedRight = Value; }
	FORCEINLINE void SetUseControllerRotationYaw(bool Value) { bUseControllerRotationYaw = Value; }

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadOnly)
	float MoveSpeed;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedForward;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedRight;

	UPROPERTY(EditAnywhere)
	float MoveSpeedThreshold = 20.f;

	UPROPERTY(EditDefaultsOnly)
	UWidgetComponent* MainMenuWidgetComponent;

protected:
	UCharacterMovementComponent* MovementComponent;

private:
	UMainMenuWidget* MainMenuWidget;
};
