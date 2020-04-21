// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
//#include "Tank.h"
#include "TankAIController.generated.h"

class ATank; // Forward Declaration


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* ControlledTank;
	
	ATank* PlayerTank;

	// How close the AI tank can get to the player
	float AcceptanceRadius = 3000;
};
