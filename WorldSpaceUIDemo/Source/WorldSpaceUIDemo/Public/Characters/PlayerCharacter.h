// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class WORLDSPACEUIDEMO_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Display)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Display)
	UCameraComponent* Camera;

public:
	FORCEINLINE void SetMoveSpeedForward(float Value) { MoveSpeedForward = Value; }
	FORCEINLINE void SetMoveSpeedRight(float Value) { MoveSpeedRight = Value; }

protected:
	virtual void BeginPlay() override;

	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeed;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedForward;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeedRight;
};
