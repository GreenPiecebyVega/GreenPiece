// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/LoginWidget.h"
#include "GreenPieceGameInstance.generated.h"

/**
 * Green Piece Main Game Instance
 * Each session/channel will have a game instance, this main class will share states between many instances.
 */
UCLASS()
class GREENPIECE_API UGreenPieceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    UGreenPieceGameInstance(const FObjectInitializer& ObjectInitializer);

    virtual void Init();
    void ShowLoginWidget();

private:
    TSubclassOf<class ULoginWidget> LoginWidgetClass;
};
