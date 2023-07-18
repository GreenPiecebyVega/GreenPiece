// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GreenPieceGameMode.generated.h"

UCLASS(minimalapi)
class AGreenPieceGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AGreenPieceGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal) override;

protected:
	UFUNCTION(BlueprintCallable)
	bool CreateHostBeacon();

	virtual void BeginPlay() override;
	
	class AGreenPieceBeaconHostObject* GreenPieceHostObject;

	TArray<class APlayerStart*> FreePlayerStarts;
};



