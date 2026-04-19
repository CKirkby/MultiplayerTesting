// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetDummy.h"

#include <string>

#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"

ATargetDummy::ATargetDummy()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(MeshComponent);

}

void ATargetDummy::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;
}

void ATargetDummy::OnTakeDamage(const float Damage)
{
	Server_OnTakeDamage(Damage);
}

void ATargetDummy::OnRep_CurrentHealth() const
{
	OnTakeDamageEvent.Broadcast();
}

void ATargetDummy::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ATargetDummy, CurrentHealth);
}

void ATargetDummy::Server_OnTakeDamage_Implementation(const float Damage)
{
	CurrentHealth -= Damage;
	
	OnTakeDamageEvent.Broadcast();
	
	if (CurrentHealth <= 0.0f)
	{
		CurrentHealth = MaxHealth;
	}
}

