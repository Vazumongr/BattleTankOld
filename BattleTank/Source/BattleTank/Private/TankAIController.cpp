// Copyright Troy Records Jr.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
// Depends on movement component for ai pathfinding

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(PlayerTank && AimingComponent))
	{
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check if radius is in cm

		//Aim at the player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if(AimingComponent->GetFiringState() == EFiringStatus::Locked)
			AimingComponent->Fire();
	}
	
}