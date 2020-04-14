// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Tank.generated.h"

class UTankBarrel; // Forward Declaration
class UTankTurret; // Forward Declaration
class UTankAimingComponent; // Forward Declaration
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	ATank();
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 20000.f;	// TODO find sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
	
	float ReloadTimeInSeconds = 3.f;
	float LastFireTime = -3.f;
	
};
