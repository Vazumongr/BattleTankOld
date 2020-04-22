// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "GameFramework/DefaultPawn.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank.cpp Construct"), *TankName);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank.cpp BeginPlay"), *TankName);
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && bIsReloaded)
	{
	// Spawn projectile at socket location of barrel
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint, 
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		if (!Projectile) 
		{ 
			UE_LOG(LogTemp, Error, TEXT("Projectile Blueprint is None. PLEASE FIX THIS BUG EPIC"))
			return; 
		}
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}


	

}