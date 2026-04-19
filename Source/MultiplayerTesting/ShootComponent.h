// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent.generated.h"


class UArrowComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYERTESTING_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShootComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShootComponent")
	USceneComponent* FireLocation = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShootComponent")
	TSubclassOf<AActor> ProjectileClass = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MyFloat = 32.0f;

public:	
	
	UFUNCTION(Server, Reliable)
	void Server_OnShoot();

	UFUNCTION(BlueprintCallable)
	void OnShoot();

		
};
