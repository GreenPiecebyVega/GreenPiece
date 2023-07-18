// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "Controllers/GreenPiecePlayerController.h"
#include "GreenPieceGameInstance.h"
#include "GameFramework/GameUserSettings.h"
#include "UObject/ConstructorHelpers.h"

AGreenPiecePlayerController::AGreenPiecePlayerController() {}

void AGreenPiecePlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority() && IsLocalController())
    {
        UGreenPieceGameInstance* GameInstance = Cast<UGreenPieceGameInstance>(GetGameInstance());
        if (GameInstance && GameInstance->LoginWidgetClass)
        {
            GameInstance->LoginWidget = CreateWidget<UUserWidget>(this, GameInstance->LoginWidgetClass);

            if (GameInstance->LoginWidget)
            {
                GameInstance->LoginWidget->AddToViewport();

                FInputModeUIOnly InputModeData;
                InputModeData.SetWidgetToFocus(GameInstance->LoginWidget->TakeWidget());
                InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
            }
        }
    }
}