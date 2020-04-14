// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		//Move towards the player

		//Aim at the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if ready
		ControlledTank->Fire();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: Player tank cannot be found by %s"), GetWorld()->DeltaTimeSeconds, *GetName());
	}
	
}