// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GreenPiecePlayerController.generated.h"

UCLASS()
class GREENPIECE_API AGreenPiecePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    AGreenPiecePlayerController();

private:
    virtual void BeginPlay() override;
};
