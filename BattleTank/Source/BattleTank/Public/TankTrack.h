// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// Sets throttle between 1 and -1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max Force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float MaxTrackDrivingForce = 400000.f; // Assume 40 ton tank and 1g acceleration

	// Max velocity of tank.
	UPROPERTY(EditDefaultsOnly)
	float MaxTankSpeed = 60; // 60 m/s?

protected:
	void ApplySidewaysForce();
	void DriveTrack();
	virtual void BeginPlay() override;

private:
	UTankTrack();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;
};
