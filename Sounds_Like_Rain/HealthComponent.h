// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOUNDS_LIKE_RAIN_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	float Health;
	const float MaxHealth = 100;
	bool bDead;
	
public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	const float GetHealth();

	UFUNCTION(BlueprintCallable)
	void SetHealth (float HitPoints);

	UFUNCTION(BlueprintCallable)
	const bool GetDead();

	UFUNCTION(BlueprintCallable)
	void SetDead (bool IsDead);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Damage;
};
