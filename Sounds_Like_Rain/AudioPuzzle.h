// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioPuzzle.generated.h"

UCLASS()
class SOUNDS_LIKE_RAIN_API AAudioPuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAudioPuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AActor* DoorToOpen;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<AActor*> CorrectBellOrder;

	TArray<AActor*> StruckBellOrder;

	bool bDoorOpened;

	bool bPuzzleCompleted;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector DoorToOpenNewLocation;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FRotator DoorToOpenNewRotation;
	
	FVector DoorToOpenOriginalLocation;

	FRotator DoorToOpenOriginalRotation;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float InterpTime;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bSmoothLerp;
	
	float endOfInterpolation;
	
	float InterpolationAlpha;

	bool IsNearlyEqual (FVector x, FVector y, float z);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintSetter=SetStruckBell)
	AActor* StruckBell;

	UFUNCTION(BlueprintImplementableEvent)
	void StartDoorOpen();
	UFUNCTION(BlueprintImplementableEvent)
	void EndDoorOpen();

	UFUNCTION(BlueprintSetter)
	void SetStruckBell(AActor* CurrentBell);
};