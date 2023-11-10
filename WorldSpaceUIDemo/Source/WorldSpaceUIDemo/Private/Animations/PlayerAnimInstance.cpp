// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/PlayerAnimInstance.h"

void UPlayerAnimInstance::TurnRight(bool Right)
{
	if (MontageTurn)
	{
		Montage_Play(MontageTurn);
		FName SectionName = Right ? FName("TurnLeft") : FName("TurnRight");
		Montage_JumpToSection(SectionName, MontageTurn);
	}
}
