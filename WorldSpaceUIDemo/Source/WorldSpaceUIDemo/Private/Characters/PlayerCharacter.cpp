// Copyright 2023, Sherwin Espela. All Rights Reserved.

#include "Characters/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Animation/AnimMontage.h"
#include "Animations/PlayerAnimInstance.h"
#include "Components/WidgetComponent.h"
#include "Characters/HUDCameraActor.h"
#include "UI/MainMenuWidget.h"
#include "HUD/FloatingWidgetComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritYaw = true;
	CameraBoom->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	MovementComponent = GetCharacterMovement();
	MovementComponent->bOrientRotationToMovement = true;
	MovementComponent->RotationRate = FRotator(0.f, 400.f, 0.f);
	MovementComponent->MaxWalkSpeed = 300.f;
	MovementComponent->MinAnalogWalkSpeed = 50.f;

	MainMenuWidgetComponent = CreateDefaultSubobject<UFloatingWidgetComponent>(TEXT("Indicator Widget"));
	MainMenuWidgetComponent->SetupAttachment(GetRootComponent());
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	bUseControllerRotationYaw = false;

	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	MainMenuWidget = Cast<UMainMenuWidget>(MainMenuWidgetComponent->GetUserWidgetObject());
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveSpeed = UKismetMathLibrary::VSizeXY(MovementComponent->Velocity);
}

void APlayerCharacter::TurnRight(bool Right)
{
	auto PlayerAnimInstance = Cast<UPlayerAnimInstance>(GetMesh()->GetAnimInstance());
	if (PlayerAnimInstance) PlayerAnimInstance->TurnRight(Right);
}

void APlayerCharacter::SetOrientRotationToMovement(bool Value)
{
	if (MovementComponent)
	{
		MovementComponent->bOrientRotationToMovement = Value;
	}
}

UMainMenuWidget* APlayerCharacter::GetMainMenuWidget()
{
	if (MainMenuWidget == nullptr)
	{
		MainMenuWidget = Cast<UMainMenuWidget>(MainMenuWidgetComponent->GetUserWidgetObject());
	}

	return MainMenuWidget;
}
