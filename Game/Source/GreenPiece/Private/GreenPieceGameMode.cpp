// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "GreenPieceGameMode.h"

#include "OnlineBeaconHost.h"
#include "../Public/Network/GreenPieceBeaconHostObject.h"

#include "../Public/GreenPieceCharacter.h"
#include "../Public/Controllers/GreenPiecePlayerController.h"

#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"

AGreenPieceGameMode::AGreenPieceGameMode(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	GreenPieceHostObject  = nullptr;
	DefaultPawnClass	  = AGreenPieceCharacter::StaticClass();
	PlayerControllerClass = AGreenPiecePlayerController::StaticClass();
}

void AGreenPieceGameMode::BeginPlay()
{
    Super::BeginPlay();
	CreateHostBeacon();
}

void AGreenPieceGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
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
				return true;
			}
		}
	}
	return false;
}

FString AGreenPieceGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	const FString Error = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
	if (Error.Len() > 0)
	{
		return Error;
	}
	return TEXT("");
}
