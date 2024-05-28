// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioPuzzlePiece.h"


// Sets default values
AAudioPuzzlePiece::AAudioPuzzlePiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	fBellPitch = 0;
}

// Called when the game starts or when spawned
void AAudioPuzzlePiece::BeginPlay()
{
	Super::BeginPlay();

	Tags.Add(FName( "PuzzlePiece"));

	if (fBellPitch <0)
	{
		fBellPitch = 0;
	}
	else if (fBellPitch>3)
	{
		fBellPitch = 3;
	}
}

// Called every frame
void AAudioPuzzlePiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}