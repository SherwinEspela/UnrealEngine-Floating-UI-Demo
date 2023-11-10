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
	EnhancedInputComponent->BindAction(InputActionLookAround, ETriggerEvent::Triggered, this, &AWSPlayerController::LookAround);
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
		PlayerCharacter->SetMoveSpeedForward(MovementVector.Y * MaxSpeed);
		PlayerCharacter->SetMoveSpeedRight(MovementVector.X * MaxSpeed);
	}
}

void AWSPlayerController::LookAround(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	PlayerCharacter->AddControllerYawInput(LookAxisVector.X);
	PlayerCharacter->AddControllerPitchInput(LookAxisVector.Y);

	FRotator Rotation = GetControlRotation();
	IsRotatingRight = Rotation.Yaw > CurrentRightAngleValue;
	CurrentRightAngleValue = Rotation.Yaw;

	int AngleY = FMath::Floor(Rotation.Yaw);
	//UE_LOG(LogTemp, Warning, TEXT("AngleY ===== %i"), AngleY);

	if (AngleY == 90)
	{
		if (IsRotatingRight)
		{
			UE_LOG(LogTemp, Warning, TEXT("Is rotating RIGHT..."));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Is rotating LEFT..."));
		}
	}
}

void AWSPlayerController::ReloadLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
