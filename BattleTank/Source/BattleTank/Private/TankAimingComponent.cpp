// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//auto TankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	// Suply default params to prevent Unreal bug
	bool bFavorHighArc = false;
	float CollisionRadius = 0.0;
	float OverrideGravityZ = 0.0;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity (
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		bFavorHighArc, 
		CollisionRadius,
		OverrideGravityZ, 
		ESuggestProjVelocityTraceOption::DoNotTrace 
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveTowards(AimDirection);
	}
	return;
}

void UTankAimingComponent::MoveTowards(FVector AimDirection)
{
	//FVector TestVector = FVector(1.0, -1.0, 0.0);
	//auto TestRotator = TestVector.Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("FVector(1.0, -1.0, 0.0) give rotation %s"), *TestRotator.ToString());
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
	return;
}

void UTankAimingComponent::SetBarrelAndTurretReference(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}
