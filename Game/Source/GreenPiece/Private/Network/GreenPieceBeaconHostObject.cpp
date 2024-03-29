// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#include "Network/GreenPieceBeaconHostObject.h"
#include "Network/GreenPieceOnlineBeaconClient.h"

AGreenPieceBeaconHostObject::AGreenPieceBeaconHostObject()
{
	ClientBeaconActorClass = AGreenPieceOnlineBeaconClient::StaticClass();
	BeaconTypeName = ClientBeaconActorClass->GetName();
}

void AGreenPieceBeaconHostObject::OnClientConnected(AOnlineBeaconClient* NewClientActor, UNetConnection* ClientConnection)
{
	Super::OnClientConnected(NewClientActor, ClientConnection);

	if (NewClientActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cliente conectado COM sucesso."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cliente conectado SEM sucesso."));
	}
}
