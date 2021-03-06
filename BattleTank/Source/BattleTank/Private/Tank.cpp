// Fill out your copyright notice in the Description page of Project Settings.
#include "BattleTank.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds ;

	if (Barrel && isReloaded)
	{
		FVector BarrelSocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator BarrelSocketRotation = Barrel->GetSocketRotation(FName("Projectile"));

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelSocketLocation, BarrelSocketRotation);
		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::SetBarrelAndTurretReference(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	TankAimingComponent->SetBarrelAndTurretReference(BarrelToSet, TurretToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
