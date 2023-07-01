// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "GreenPieceGameMode.h"
#include "GreenPieceCharacter.h"

#include "GreenPieceHUD.h"

void AGreenPieceGameMode::BeginPlay()
{
    Super::BeginPlay();

    // HUD class
    HUDClass = AGreenPieceHUD::StaticClass();
}