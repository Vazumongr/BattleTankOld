// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"




void UTankTurret::Rotate(float RelativeSpeed)
{
	auto Time = GetWorld()->DeltaTimeSeconds;
	//UE_LOG(LogTemp, Warning, TEXT("%f: UTankTurret::Rotate is being called with a speed of: %f"), Time, RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}