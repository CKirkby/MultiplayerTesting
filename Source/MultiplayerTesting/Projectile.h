// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USphereComponent;

UCLASS()
class MULTIPLAYERTESTING_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	class UProjectileMovementComponent* MovementComponent;

	// Speed of the projectile
	UPROPERTY(EditAnywhere, Category = Projectile)
	float Speed = 4000.0f;

	// Lifetime of the projectile
	UPROPERTY(EditAnywhere, Category = Projectile)
	float Lifetime = 5.0f;

private:
	FTimerHandle LifetimeTimerHandle;
	
	void DestroyProjectile();
};
