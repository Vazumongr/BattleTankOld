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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	APawn* PlayerTank;

	UTankAimingComponent* AimingComponent = nullptr;

	// How close the AI tank can get to the player
	float AcceptanceRadius = 3000;
};
