// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetDummy.generated.h"

class UBoxComponent;

UCLASS()
class MULTIPLAYERTESTING_API ATargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	ATargetDummy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxComponent = nullptr;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTakeDamageEvent);
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnTakeDamageEvent OnTakeDamageEvent;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

public:	
	
	UFUNCTION(Server, Reliable) 
	void Server_OnTakeDamage(float Damage);
	UFUNCTION(BlueprintCallable, Category = "Health")
	void OnTakeDamage(float Damage);
	UFUNCTION()
	void OnRep_CurrentHealth() const;
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

};
