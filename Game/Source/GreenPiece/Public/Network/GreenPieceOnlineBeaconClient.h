// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconClient.h"
#include "GreenPieceOnlineBeaconClient.generated.h"

/**
 * 
 */
UCLASS()
class GREENPIECE_API AGreenPieceOnlineBeaconClient : public AOnlineBeaconClient
{
	GENERATED_BODY()
public:
	AGreenPieceOnlineBeaconClient();
	bool CastServerConnection();

protected:
	bool ConnectToServer();

	virtual void OnConnected() override;
	virtual void OnFailure() override;
};
