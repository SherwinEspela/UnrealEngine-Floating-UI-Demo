// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HUDCameraActor.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class WORLDSPACEUIDEMO_API AHUDCameraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AHUDCameraActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Display)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Display)
	UCameraComponent* Camera;

};
