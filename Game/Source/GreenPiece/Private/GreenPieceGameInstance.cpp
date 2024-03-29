// Green Piece - 929641795 Copyright © Vega Soft. All Rights Reserved.

#include "GreenPieceGameInstance.h"

#include "Subsystems/GPSessionSubsystem.h"

#include "OnlineBeaconClient.h"
#include "Network/GreenPieceOnlineBeaconClient.h"

#include "UI/LoginWidget.h"

UGreenPieceGameInstance::UGreenPieceGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<ULoginWidget> BP_LoginWidget(TEXT("/Game/Levels/Login/LoginWidget"));
	if (!ensure(BP_LoginWidget.Class != nullptr)) return;
	LoginWidgetClass = BP_LoginWidget.Class;
	GreenPieceBeaconClient = nullptr;
}

void UGreenPieceGameInstance::Init()
{
	Super::Init();
	if (AOnlineBeaconClient* Client = GetWorld()->SpawnActor<AOnlineBeaconClient>(AOnlineBeaconClient::StaticClass()))
	{
		GreenPieceBeaconClient = GetWorld()->SpawnActor<AGreenPieceOnlineBeaconClient>(AGreenPieceOnlineBeaconClient::StaticClass());
		GreenPieceBeaconClient->CastServerConnection();
	}
}