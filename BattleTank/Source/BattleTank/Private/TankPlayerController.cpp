// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController not possessing a tank..."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	// Get world location of linetrace through crosshair
	GetSightRayHitLocation(HitLocation);

	UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *HitLocation.ToString());
}

// Get world location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
