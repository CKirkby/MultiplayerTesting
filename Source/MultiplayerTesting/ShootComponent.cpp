// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootComponent.h"
#include "Engine/World.h"

UShootComponent::UShootComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UShootComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UShootComponent::OnShoot()
	{
	if (GetOwner()->HasAuthority())
	{
		Server_OnShoot_Implementation();
	}
	else
	{
		Server_OnShoot();
	}
}

void UShootComponent::Server_OnShoot_Implementation()
{
	if (ProjectileClass && FireLocation)
	{
		FVector Location = FireLocation->GetComponentLocation();
		FRotator Rotation = FireLocation->GetComponentRotation();
		if (GetWorld()->SpawnActor<AActor>(ProjectileClass, Location, Rotation))
		{
			// Do stuff
		}
	}
}
