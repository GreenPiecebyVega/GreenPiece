// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * Login Widget UI
 */
UCLASS()
class GREENPIECE_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY(meta = (BindWidget))
    class UEditableTextBox* TextBoxFieldLogin;

    UPROPERTY(meta = (BindWidget))
    class UEditableTextBox* TextBoxFieldPassword;
};
