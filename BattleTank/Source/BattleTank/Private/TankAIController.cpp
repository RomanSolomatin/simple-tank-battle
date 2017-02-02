// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController can not find player tank..."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController found player: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	ATankPlayerController*  TankPlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!TankPlayerController) { return nullptr; }
	return TankPlayerController->GetControlledTank();
}