// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Animation/AnimMontage.h"
#include "Animations/PlayerAnimInstance.h"
#include "Components/WidgetComponent.h"

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

	MainMenuWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Indicator Widget"));
	MainMenuWidgetComponent->SetupAttachment(GetRootComponent());
	//MainMenuWidgetComponent->SetDrawSize(FVector2D(40.f, 40.f));
	MainMenuWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	bUseControllerRotationYaw = false;
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
