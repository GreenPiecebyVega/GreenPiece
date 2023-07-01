// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "Controllers/GreenPiecePlayerController.h"
#include "GreenPieceGameInstance.h"

void AGreenPiecePlayerController::BeginPlay()
{
    Super::BeginPlay();

    UGreenPieceGameInstance* GameInstance = Cast<UGreenPieceGameInstance>(GetGameInstance());
    if (GameInstance)
    {
        GameInstance->ShowLoginWidget();
    }
}