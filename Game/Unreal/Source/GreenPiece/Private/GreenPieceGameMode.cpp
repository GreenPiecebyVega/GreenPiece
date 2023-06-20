// Copyright Epic Games, Inc. All Rights Reserved.

#include "GreenPieceGameMode.h"
#include "GreenPieceCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGreenPieceGameMode::AGreenPieceGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
