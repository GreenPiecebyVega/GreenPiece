// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/LoginWidget.h"
#include "GreenPieceGameInstance.generated.h"

UCLASS()
class GREENPIECE_API UGreenPieceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    UGreenPieceGameInstance(const FObjectInitializer& ObjectInitializer);
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Login")
        TSubclassOf<class ULoginWidget> LoginWidgetClass;

    UPROPERTY(BlueprintReadOnly, Category = "Login")
        UUserWidget* LoginWidget;
private:
    virtual void Init();
};
