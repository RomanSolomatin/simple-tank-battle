// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel; 
class UTankTurret;

/**
* Allow taank component to aim at a location
* and delegate it to the barrel.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelAndTurretReference(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	
	// Sets default values for this component's properties
	UTankAimingComponent();

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveTowards(FVector AimDirection);
};
