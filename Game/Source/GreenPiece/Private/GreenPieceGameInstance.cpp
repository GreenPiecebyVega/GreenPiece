// Green Piece - 929641795 Copyright © Vega Soft. All Rights Reserved.

#include "GreenPieceGameInstance.h"
#include "UI/LoginWidget.h"

UGreenPieceGameInstance::UGreenPieceGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<ULoginWidget> BP_LoginWidget(TEXT("/Game/Levels/Login/LoginWidget"));
	if (!ensure(BP_LoginWidget.Class != nullptr)) return;

	LoginWidgetClass = BP_LoginWidget.Class;
}