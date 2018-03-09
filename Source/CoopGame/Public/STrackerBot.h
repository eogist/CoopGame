// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STrackerBot.generated.h"

class UStaticMeshComponent;
class USHealthComponent;

UCLASS()
class COOPGAME_API ASTrackerBot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASTrackerBot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USHealthComponent* HealthComponent = nullptr;

	FVector GetNextPathPoint();

	UFUNCTION()
	void HandleTakeDamage(USHealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	FVector NextPathPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Bot")
	float MovementForce;

	UPROPERTY(EditDefaultsOnly, Category = "Bot")
	bool bUseVelocityChange;

	UPROPERTY(EditDefaultsOnly, Category = "Bot")
	float RequiredDistanceToTarget;

	UMaterialInstanceDynamic* MaterialInst;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
