
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

class UProgressBar;
class UTextBlock;

/**
 * 
 */
UCLASS( abstract )
class PRUEBA_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
		UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* HealthLabel;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* MaxHealthLabel;

};
