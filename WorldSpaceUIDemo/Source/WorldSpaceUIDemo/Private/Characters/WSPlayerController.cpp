// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "Characters/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/HUDCameraActor.h"
#include "UI/MainMenuWidget.h"
#include "HUD/FloatingWidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

void AWSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContextPlayer, 0);

	bIsViewingPlayerCamera = true;
	PlayerCharacter = Cast<APlayerCharacter>(GetPawn());
	HUDCamera = GetWorld()->SpawnActor<AHUDCameraActor>(HUDCameraActorClass);

	PlayerCharacter->GetMainMenuWidgetComponent()->OnFloatingWidgetModalDisplayChanged.AddDynamic(this, &AWSPlayerController::HandleModalDisplayChanged);
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
	EnhancedInputComponent->BindAction(InputActionYButton, ETriggerEvent::Triggered, this, &AWSPlayerController::ToggleCamera);
	EnhancedInputComponent->BindAction(InputActionDPadUpButton, ETriggerEvent::Triggered, this, &AWSPlayerController::DPadUpTapped);
	EnhancedInputComponent->BindAction(InputActionDPadDownButton, ETriggerEvent::Triggered, this, &AWSPlayerController::DPadDownTapped);
	EnhancedInputComponent->BindAction(InputActionDPadLeftButton, ETriggerEvent::Triggered, this, &AWSPlayerController::DPadLeftTapped);
	EnhancedInputComponent->BindAction(InputActionDPadRightButton, ETriggerEvent::Triggered, this, &AWSPlayerController::DPadRightTapped);
	EnhancedInputComponent->BindAction(InputActionL1Button, ETriggerEvent::Triggered, this, &AWSPlayerController::ButtonL1Tapped);
	EnhancedInputComponent->BindAction(InputActionR1Button, ETriggerEvent::Triggered, this, &AWSPlayerController::ButtonR1Tapped);
	EnhancedInputComponent->BindAction(InputActionAButton, ETriggerEvent::Triggered, this, &AWSPlayerController::ButtonATapped);
	EnhancedInputComponent->BindAction(InputActionBButton, ETriggerEvent::Triggered, this, &AWSPlayerController::ButtonBTapped);
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

void AWSPlayerController::ToggleCamera()
{
	if (bIsViewingPlayerCamera)
	{
		FString SocketName = TEXT("HeadHUDSocket");
		FVector SocketLocation = PlayerCharacter->GetMesh()->GetSocketLocation(*SocketName);
		HUDCamera->SetActorLocation(SocketLocation);
		FRotator SocketRotation = PlayerCharacter->GetActorRotation();
		SocketRotation.Yaw -= 33.f;
		HUDCamera->SetActorRotation(SocketRotation);

		SetViewTargetWithBlend(HUDCamera, CameraSwitchBlendTime);
		PlayerCharacter->GetMainMenuWidgetComponent()->ShowMainMenu();
		PlayerCharacter->OnTurnScreenLightOn(true);
	}
	else {
		if (bIsDisplayingModal) return;
		SetViewTargetWithBlend(PlayerCharacter, CameraSwitchBlendTime);
		PlayerCharacter->GetMainMenuWidgetComponent()->HideMainMenu();
		PlayerCharacter->OnTurnScreenLightOn(false);
		bIsDisplayingDataBios = true;
	}

	if (SfxMainMenu) UGameplayStatics::PlaySound2D(this, SfxMainMenu);
	bIsViewingPlayerCamera = !bIsViewingPlayerCamera;
}

void AWSPlayerController::DPadUpTapped()
{
	if (bIsViewingPlayerCamera) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->MoveSelectionUp();
}

void AWSPlayerController::DPadDownTapped()
{
	if (bIsViewingPlayerCamera) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->MoveSelectionDown();
}

void AWSPlayerController::DPadLeftTapped()
{
	if (bIsViewingPlayerCamera) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->MoveSelectionLeft();
}

void AWSPlayerController::DPadRightTapped()
{
	if (bIsViewingPlayerCamera) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->MoveSelectionRight();
}

void AWSPlayerController::ButtonL1Tapped()
{
	if (bIsViewingPlayerCamera) return;
	if (bIsDisplayingDataBios) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->MoveTopBarSelectionLeft();
	bIsDisplayingDataBios = true;
}

void AWSPlayerController::ButtonR1Tapped()
{
	if (bIsViewingPlayerCamera) return;
	if (!bIsDisplayingDataBios) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->MoveTopBarSelectionRight();
	bIsDisplayingDataBios = false;
}

void AWSPlayerController::ButtonATapped()
{
	if (bIsViewingPlayerCamera) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->OpenModal();
}

void AWSPlayerController::ButtonBTapped()
{
	if (bIsViewingPlayerCamera) return;
	PlayerCharacter->GetMainMenuWidgetComponent()->CloseModal();
}

void AWSPlayerController::HandleModalDisplayChanged(bool IsDisplayingModal)
{
	bIsDisplayingModal = IsDisplayingModal;
}
