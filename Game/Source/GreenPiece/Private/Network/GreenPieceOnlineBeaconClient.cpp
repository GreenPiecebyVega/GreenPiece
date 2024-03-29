// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.


#include "Network/GreenPieceOnlineBeaconClient.h"

AGreenPieceOnlineBeaconClient::AGreenPieceOnlineBeaconClient() 
{

}

bool AGreenPieceOnlineBeaconClient::CastServerConnection()
{
    return ConnectToServer();
}

bool AGreenPieceOnlineBeaconClient::ConnectToServer()
{   
    const FString& Server = "127.0.0.1";
    FURL GPServer = FURL(nullptr, *Server, ETravelType::TRAVEL_Absolute);
    GPServer.Port = 7787;
    return InitClient(GPServer);
}

void AGreenPieceOnlineBeaconClient::OnConnected()
{
    UE_LOG(LogTemp, Warning, TEXT("Client connected with the host beacon successfuly!"))
}

void AGreenPieceOnlineBeaconClient::OnFailure()
{
    UE_LOG(LogTemp, Warning, TEXT("Client failed to connect to host beacon!"))
}
