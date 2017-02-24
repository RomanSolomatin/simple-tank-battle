// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * TankMovementComponent is a NavMovementComponent with ability to call IntendMoveForward.
 */
UCLASS()
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:	
    UFUNCTION(BlueprintCallable, Category = Move)
	void IntendMoveForward(float Throw);	
};
