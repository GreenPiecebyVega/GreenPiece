// Green Piece - 929641795 Copyright © Vega Soft. All Rights Reserved.

#include "GreenPieceGameInstance.h"
#include "GameFramework/GameUserSettings.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/LoginWidget.h"

/*
 * Constructor
 */
UGreenPieceGameInstance::UGreenPieceGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<ULoginWidget> BP_LoginWidget(TEXT("/Game/GreenPiece/Blueprints/Widgets/LoginWidget"));
	if (!ensure(BP_LoginWidget.Class != nullptr)) return;

	LoginWidgetClass = BP_LoginWidget.Class;
}

void UGreenPieceGameInstance::Init()
{
}

/*
 * Login
 */
void UGreenPieceGameInstance::ShowLoginWidget()
{
	if (!ensure(LoginWidgetClass)) return;

	ULoginWidget* Login = CreateWidget<ULoginWidget>(this, LoginWidgetClass);
	Login->AddToViewport();

	APlayerController* LocalPlayerController = GetFirstLocalPlayerController();
	if (!ensure(LocalPlayerController)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Login->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	LocalPlayerController->SetInputMode(InputModeData);
	LocalPlayerController->bShowMouseCursor = true;
}