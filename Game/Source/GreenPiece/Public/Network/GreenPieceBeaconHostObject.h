// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHostObject.h"
#include "GreenPieceBeaconHostObject.generated.h"

/**
 * 
 */
UCLASS()
class GREENPIECE_API AGreenPieceBeaconHostObject : public AOnlineBeaconHostObject
{
	GENERATED_BODY()
public:
	AGreenPieceBeaconHostObject();

protected:
	virtual void OnClientConnected(AOnlineBeaconClient* NewClientActor, UNetConnection* ClientConnection) override;
};
