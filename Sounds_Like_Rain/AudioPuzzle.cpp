// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioPuzzle.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAudioPuzzle::AAudioPuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorToOpenNewLocation = FVector(0,0,0);
	DoorToOpenNewRotation = FRotator(0,0,0);

	bDoorOpened = false;
	
	InterpTime = 0.1;
	
	endOfInterpolation = 0;

	InterpolationAlpha = 0;

	bSmoothLerp = true;
}

// Called when the game starts or when spawned
void AAudioPuzzle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAudioPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bDoorOpened)
	{
		endOfInterpolation += DeltaTime;

		InterpolationAlpha = endOfInterpolation/InterpTime;

		if(InterpolationAlpha>1)
		{
			InterpolationAlpha = 1;
		}

		if (bSmoothLerp)
		{
			DoorToOpen->SetActorLocation(FMath::Lerp(DoorToOpenOriginalLocation,DoorToOpenOriginalLocation+DoorToOpenNewLocation,InterpolationAlpha));
            DoorToOpen->SetActorRotation(FMath::Lerp(DoorToOpenOriginalRotation,DoorToOpenOriginalRotation+DoorToOpenNewRotation,InterpolationAlpha));
			
			UE_LOG(LogTemp,Warning, TEXT("The Door Is Opening"));
		
			if (endOfInterpolation >= InterpTime)
			{
				bDoorOpened = false;
				EndDoorOpen();
				UE_LOG(LogTemp,Warning, TEXT("The Door has opened"));
			}
		}
		else
		{
			// if (DoorToOpenOriginalLocation)
			// {
			// 	DoorToOpen->SetActorLocation(FMath::Lerp(DoorToOpen->GetActorLocation(),DoorToOpenOriginalLocation+DoorToOpenNewLocation,DeltaTime/InterpTime));
			// 	DoorToOpen->SetActorRotation(FMath::Lerp(DoorToOpen->GetActorRotation(),DoorToOpenOriginalRotation+DoorToOpenNewRotation,DeltaTime/InterpTime));
			// }
			
			DoorToOpen->SetActorLocation(FMath::Lerp(DoorToOpen->GetActorLocation(),DoorToOpenOriginalLocation+DoorToOpenNewLocation,DeltaTime/InterpTime));
			DoorToOpen->SetActorRotation(FMath::Lerp(DoorToOpen->GetActorRotation(),DoorToOpenOriginalRotation+DoorToOpenNewRotation,DeltaTime/InterpTime));

			UE_LOG(LogTemp,Warning, TEXT("The Door Is Opening"));
			
			if (IsNearlyEqual(DoorToOpen->GetActorLocation(),DoorToOpenOriginalLocation+DoorToOpenNewLocation, 1))
			{
				bDoorOpened = false;
				EndDoorOpen();
				UE_LOG(LogTemp,Warning, TEXT("The Door has opened"));
			}
		}
	}
}

void AAudioPuzzle::SetStruckBell(AActor* CurrentBell)
{
	StruckBellOrder.Add(CurrentBell);

	if (StruckBellOrder.Num()>CorrectBellOrder.Num())
	{
		StruckBellOrder.Empty();
		StruckBellOrder.Add(CurrentBell);
	}
	
	if (StruckBellOrder.Last()!=CorrectBellOrder[StruckBellOrder.Num()-1])
	{
		StruckBellOrder.Empty();
	}
	
	if (StruckBellOrder.Num()==CorrectBellOrder.Num())
	{
		checkf(IsValid(DoorToOpen),TEXT("There was no Door Actor asaigned to the AudioPuzzleMaster"));

		if (bPuzzleCompleted)
		{
			return;
		}

		DoorToOpenOriginalLocation = FVector(DoorToOpen->GetActorLocation());
		DoorToOpenOriginalRotation = FRotator(DoorToOpen->GetActorRotation());

		//make a check to see if puzzle has already been done
		
		if (endOfInterpolation < InterpTime)
		{
			StartDoorOpen();
			bDoorOpened = true;
		}
		
		UE_LOG(LogTemp, Warning, TEXT("You have Completed the puzzle!"));
		
		bPuzzleCompleted = true;
	}
}


bool AAudioPuzzle::IsNearlyEqual(FVector x, FVector y, float z)
 {
	if (FMath::IsNearlyEqual(x.X,y.X, z) && FMath::IsNearlyEqual(x.Y,y.Y, z) &&	FMath::IsNearlyEqual(x.Z,y.Z, z))
	{
		return true;
	}
	
	return false;
 }