// Copyright Troy Records Jr.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent; // Forward Declaration


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

protected:

	// How close the AI tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UTankAimingComponent* AimingComponent = nullptr;

};
