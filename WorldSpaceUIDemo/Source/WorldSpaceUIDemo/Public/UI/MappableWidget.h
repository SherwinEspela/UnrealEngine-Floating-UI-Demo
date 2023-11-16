// Copyright 2023 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MappableWidget.generated.h"

/**
 * 
 */
UCLASS()
class WORLDSPACEUIDEMO_API UMappableWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE UMappableWidget* MoveUp() const { return Above; }
	FORCEINLINE UMappableWidget* MoveDown() const { return Below; }
	FORCEINLINE UMappableWidget* MoveLeft() const { return Left; }
	FORCEINLINE UMappableWidget* MoveRight() const { return Right; }

public:
	FORCEINLINE void SetMapAbove(UMappableWidget* Value) { Above = Value; }
	FORCEINLINE void SetMapBelow(UMappableWidget* Value) { Below = Value; }
	FORCEINLINE void SetMapOnLeft(UMappableWidget* Value) { Left = Value; }
	FORCEINLINE void SetMapOnRight(UMappableWidget* Value) { Right = Value; }

private:
	UMappableWidget* Above;
	UMappableWidget* Below;
	UMappableWidget* Left;
	UMappableWidget* Right;
};
