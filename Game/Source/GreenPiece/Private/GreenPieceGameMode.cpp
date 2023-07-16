// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "GreenPieceGameMode.h"

#include "OnlineBeaconHost.h"
#include "../Public/Network/GreenPieceBeaconHostObject.h"

#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"

AGreenPieceGameMode::AGreenPieceGameMode()
{
	GreenPieceHostObject = nullptr;
}

bool AGreenPieceGameMode::CreateHostBeacon()
{
	if (AOnlineBeaconHost* Host = GetWorld()->SpawnActor<AOnlineBeaconHost>(AOnlineBeaconHost::StaticClass()))
	{
		if (Host->InitHost())
		{
			Host->PauseBeaconRequests(false);
			GreenPieceHostObject = GetWorld()->SpawnActor<AGreenPieceBeaconHostObject>(AGreenPieceBeaconHostObject::StaticClass());

			if (GreenPieceHostObject)
			{
				Host->RegisterHost(GreenPieceHostObject);
				UE_LOG(LogTemp, Warning, TEXT("Created HOST!!!!!!!!!!!!!"));
				return true;
			}
		}
	}
	return false;
}

void AGreenPieceGameMode::BeginPlay()
{
    Super::BeginPlay();
}

void AGreenPieceGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
	{
		FreePlayerStarts.Add(*It);

		CreateHostBeacon();
		UE_LOG(LogTemp, Warning, TEXT("Passed Created HOST"));
	}
}
