// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "Characters/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void AWSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContextPlayer, 0);

	PlayerCharacter = Cast<APlayerCharacter>(GetPawn());
}

void AWSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(InputActionMovement, ETriggerEvent::Triggered, this, &AWSPlayerController::Move);
	EnhancedInputComponent->BindAction(InputActionMovement, ETriggerEvent::Completed, this, &AWSPlayerController::MoveCompleted);
	EnhancedInputComponent->BindAction(InputActionLookAround, ETriggerEvent::Started, this, &AWSPlayerController::LookAroundStarted);
	EnhancedInputComponent->BindAction(InputActionLookAround, ETriggerEvent::Triggered, this, &AWSPlayerController::LookAround);
	EnhancedInputComponent->BindAction(InputActionLookAround, ETriggerEvent::Completed, this, &AWSPlayerController::LookAroundCompleted);
	EnhancedInputComponent->BindAction(InputActionReloadLevel, ETriggerEvent::Triggered, this, &AWSPlayerController::ReloadLevel);
}

void AWSPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	PlayerCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);
	PlayerCharacter->AddMovementInput(RightDirection, MovementVector.X);

	if (PlayerCharacter)
	{
		float MaxSpeed = PlayerCharacter->GetMovementComponent()->GetMaxSpeed();
		MoveSpeedForward = MovementVector.Y * MaxSpeed;
		MoveSpeedRight = MovementVector.X * MaxSpeed;

		bool IsWithinRange = MoveSpeedRight > -30.f && MoveSpeedRight < 30.f;
		PlayerCharacter->SetOrientRotationToMovement(IsWithinRange && !IsLookingAround);
		
		PlayerCharacter->SetMoveSpeedForward(MoveSpeedForward);
		PlayerCharacter->SetMoveSpeedRight(MoveSpeedRight);
	}
}

void AWSPlayerController::LookAround(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	PlayerCharacter->AddControllerYawInput(LookAxisVector.X);
	PlayerCharacter->AddControllerPitchInput(LookAxisVector.Y);

	IsLookingAround = true;
	PlayerCharacter->SetOrientRotationToMovement(true);
}

void AWSPlayerController::ReloadLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void AWSPlayerController::MoveCompleted()
{
	PlayerCharacter->SetOrientRotationToMovement(true);
}

void AWSPlayerController::LookAroundStarted()
{
	IsLookingAround = true;
	PlayerCharacter->SetOrientRotationToMovement(true);
}

void AWSPlayerController::LookAroundCompleted()
{
	IsLookingAround = false;
}
