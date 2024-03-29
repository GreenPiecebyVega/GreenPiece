// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GPSessionSubsystem.h"
#include "Network/GreenPieceOnlineBeaconClient.h"

#include "UI/LoginWidget.h"

#include "GreenPieceGameInstance.generated.h"

UCLASS()
class GREENPIECE_API UGreenPieceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    UGreenPieceGameInstance(const FObjectInitializer& ObjectInitializer);

    virtual void Init() override;

    TSubclassOf<class ULoginWidget> LoginWidgetClass;
    UUserWidget* LoginWidget;

protected:
    class AGreenPieceOnlineBeaconClient* GreenPieceBeaconClient;
};
