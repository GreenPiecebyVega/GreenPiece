#pragma once
// Green Piece - ID:929641795 Copyright � Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "GPSessionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGPOnCreateSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGPOnUpdateSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGPOnStartSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGPOnEndSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGPOnDestroySessionComplete, bool, Successful);
DECLARE_MULTICAST_DELEGATE_TwoParams(FGPOnFindSessionsComplete, const TArray<FOnlineSessionSearchResult>& SessionResults, bool Successful);
DECLARE_MULTICAST_DELEGATE_OneParam(FGPOnJoinSessionComplete, EOnJoinSessionCompleteResult::Type Result);

UCLASS()
class GREENPIECE_API UGPSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UGPSessionSubsystem();

	void CreateSession();
	void UpdateSession();
	void StartSession();
	void EndSession();
	void DestroySession();
	void FindSessions(int32 MaxSearchResults, bool IsLANQuery);
	void JoinGameSession(const FOnlineSessionSearchResult& SessionResult);

	FGPOnCreateSessionComplete OnCreateSessionCompleteEvent;
	FGPOnUpdateSessionComplete OnUpdateSessionCompleteEvent;
	FGPOnStartSessionComplete OnStartSessionCompleteEvent;
	FGPOnEndSessionComplete OnEndSessionCompleteEvent;
	FGPOnDestroySessionComplete OnDestroySessionCompleteEvent;
	FGPOnFindSessionsComplete OnFindSessionsCompleteEvent;
	FGPOnJoinSessionComplete OnJoinGameSessionCompleteEvent;

protected:
	void OnCreateSessionCompleted(FName SessionName, bool Successful);
	void OnUpdateSessionCompleted(FName SessionName, bool Successful);
	void OnStartSessionCompleted(FName SessionName, bool Successful);
	void OnEndSessionCompleted(FName SessionName, bool Successful);
	void OnDestroySessionCompleted(FName SessionName, bool Successful);
	void OnFindSessionsCompleted(bool Successful);
	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	bool TryTravelToCurrentSession();

private:
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;

	FOnUpdateSessionCompleteDelegate UpdateSessionCompleteDelegate;
	FDelegateHandle UpdateSessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;

	FOnEndSessionCompleteDelegate EndSessionCompleteDelegate;
	FDelegateHandle EndSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;
	TSharedPtr<FOnlineSessionSearch> LastSessionSearch;

	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;
};
