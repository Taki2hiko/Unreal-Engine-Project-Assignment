// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotator.h"

// Sets default values
ADoorRotator::ADoorRotator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create the mesh component
    DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    RootComponent = DoorMesh;

    // Initialize the rotations
    InitialRotation = DoorMesh->GetRelativeRotation();
    TargetRotation = InitialRotation + FRotator(0.0f, OpeningAngle, 0.0f);

    // Set up timeline
    FOnTimelineFloat TimelineCallback;
    TimelineCallback.BindUFunction(this, FName("UpdateDoorRotation"));
    DoorTimeline.AddInterpFloat(DoorAnimationCurve, TimelineCallback);
}

// Called when the game starts or when spawned
void ADoorRotator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorRotator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    DoorTimeline.TickTimeline(DeltaTime);
}

void ADoorRotator::UpdateDoorRotation(float Value)
{
    FRotator NewRotation = FMath::Lerp(InitialRotation, TargetRotation, Value);
    DoorMesh->SetRelativeRotation(NewRotation);
}

void ADoorRotator::OpenDoor()
{
    if (!DoorTimeline.IsPlaying())
    {
        DoorTimeline.PlayFromStart();
    }
}

