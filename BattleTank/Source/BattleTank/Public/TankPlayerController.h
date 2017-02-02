// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called in every tick 
	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
