// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AudioPuzzle.h"
#include "GameFramework/Actor.h"
#include "AudioPuzzlePiece.generated.h"


UCLASS()
class SOUNDS_LIKE_RAIN_API AAudioPuzzlePiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAudioPuzzlePiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float fBellPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AAudioPuzzle* PuzzleMaster;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
