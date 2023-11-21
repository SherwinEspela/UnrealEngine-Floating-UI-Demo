// Copyright 2023 Sherwin Espela. All rights reserved.


#include "HUD/FloatingWidgetComponent.h"
#include "UI/MainMenuWidget.h"

UFloatingWidgetComponent::UFloatingWidgetComponent()
{
	SetWidgetSpace(EWidgetSpace::World);
	SetDrawSize(FVector2D(1500.f, 700.f));
	SetGeometryMode(EWidgetGeometryMode::Cylinder);
	CylinderArcAngle = 60.f;
}

void UFloatingWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	MainMenuWidget = Cast<UMainMenuWidget>(GetUserWidgetObject());
}

void UFloatingWidgetComponent::MoveSelectionUp()
{
	MainMenuWidget->MoveSelectionUp();
}

void UFloatingWidgetComponent::MoveSelectionDown()
{
	MainMenuWidget->MoveSelectionDown();
}

void UFloatingWidgetComponent::MoveSelectionLeft()
{
	MainMenuWidget->MoveSelectionLeft();
}

void UFloatingWidgetComponent::MoveSelectionRight()
{
	MainMenuWidget->MoveSelectionRight();
}

void UFloatingWidgetComponent::MoveTopBarSelectionLeft()
{
	MainMenuWidget->MoveTopBarSelectionLeft();
}

void UFloatingWidgetComponent::MoveTopBarSelectionRight()
{
	MainMenuWidget->MoveTopBarSelectionRight();
}
