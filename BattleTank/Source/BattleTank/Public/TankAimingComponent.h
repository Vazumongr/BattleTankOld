// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	
	void AimAt(FVector HitLocation, float LaunchSpeed) const;

protected:

private:	
	UTankBarrel* Barrel = nullptr;
	UStaticMeshComponent* Turret = nullptr;
	void MoveBarrel(FVector AimDirection) const;
	
};
