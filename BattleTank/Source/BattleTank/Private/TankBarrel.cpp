// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given the max elevation speed and the frame time.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = GetWorld()->DeltaTimeSeconds * RelativeSpeed * MaxDegreesPerSecond;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	FRotator Elevation = FRotator(FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation), 0,0);
	SetRelativeRotation(Elevation);
}
