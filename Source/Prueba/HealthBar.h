
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

public:

	UFUNCTION(BlueprintCallable)
		void SetOwner(AActor* Actor) { Owner = Actor; }

protected:

	UPROPERTY(meta = (BindWidget))
		UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* HealthLabel;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* MaxHealthLabel;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:	
	
	TWeakObjectPtr<AActor> Owner;

};
