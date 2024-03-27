// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpener.h"

// Sets default values
ADoorOpener::ADoorOpener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create the mesh component
    doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    RootComponent = doorMesh;
    

    
}

// Called when the game starts or when spawned
void ADoorOpener::BeginPlay()
{
	Super::BeginPlay();
	
    // Set up timeline
    FOnTimelineFloat TimelineCallback;
    TimelineCallback.BindUFunction(this, FName("UpdateDoorRotation"));
    doorTimeline.AddInterpFloat(doorAnimationCurve, TimelineCallback);
    doorTimeline.SetLooping(false);

    initialRotation = targetRotation = GetActorRotation();
    targetRotation.Yaw += openingAngle;
}

// Called every frame
void ADoorOpener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    doorTimeline.TickTimeline(DeltaTime);
}

void ADoorOpener::UpdateDoorRotation(float Value)
{
    UE_LOG(LogTemp, Warning, TEXT("UpdateDoorRotation called. Value: %f"), Value);
    FRotator tempRo = FMath::Lerp(initialRotation, targetRotation, Value);
    SetActorRotation(tempRo);
}

void ADoorOpener::OpenDoor()
{
    UE_LOG(LogTemp, Warning, TEXT("OpenDoor function called"));
    if (!doorTimeline.IsPlaying())
    {
        doorTimeline.PlayFromStart();
    }
}

