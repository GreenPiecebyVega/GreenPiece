// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "Controllers/GreenPiecePlayerController.h"
#include "GreenPieceGameInstance.h"
#include "GameFramework/GameUserSettings.h"
#include "UObject/ConstructorHelpers.h"

AGreenPiecePlayerController::AGreenPiecePlayerController() {}

void AGreenPiecePlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("NO HasAuthority"));
    if (HasAuthority() && IsLocalController())
    {
        UGreenPieceGameInstance* GameInstance = Cast<UGreenPieceGameInstance>(GetGameInstance());
        if (GameInstance && GameInstance->LoginWidgetClass)
        {
            // Create an instance of the login widget
            GameInstance->LoginWidget = CreateWidget<UUserWidget>(this, GameInstance->LoginWidgetClass);

            // Add the login widget to the viewport
            if (GameInstance->LoginWidget)
            {
                GameInstance->LoginWidget->AddToViewport();
                UE_LOG(LogTemp, Warning, TEXT("SHOUD HAVE BEEN ADDED LOGIN TO VIEWPORT"));
                UE_LOG(LogTemp, Warning, TEXT("SHOUD HAVE BEEN ADDED LOGIN TO VIEWPORT"));
                UE_LOG(LogTemp, Warning, TEXT("SHOUD HAVE BEEN ADDED LOGIN TO VIEWPORT"));
                UE_LOG(LogTemp, Warning, TEXT("SHOUD HAVE BEEN ADDED LOGIN TO VIEWPORT"));
                UE_LOG(LogTemp, Warning, TEXT("SHOUD HAVE BEEN ADDED LOGIN TO VIEWPORT"));

                FInputModeUIOnly InputModeData;
                InputModeData.SetWidgetToFocus(GameInstance->LoginWidget->TakeWidget());
                InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
            }
        }
    }
}