// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* MyTank = Cast<ATank>(GetPawn());

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyTank is null "))
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank is null "))
	}

	if (MyTank && PlayerTank)
	{
		FVector PlayerTankLocation = PlayerTank->GetActorLocation();
		MyTank->AimAt(PlayerTankLocation);
		MyTank->Fire();
	}
}

