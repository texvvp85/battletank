// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerContoller.h"

void ATankPlayerContoller::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PLayerContller not possing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PLayerContller Possesed %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerContoller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

