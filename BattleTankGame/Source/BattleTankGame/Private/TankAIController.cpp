// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Pawn.h"
#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIContller Cant find Player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIContller Found %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}


ATank* ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerPawn) { return nullptr; }
	return Cast<ATank>(playerPawn);
}
	
