// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DoorRotator.generated.h"



UCLASS()
class TEST_API ADoorRotator : public AActor
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	ADoorRotator();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UCurveFloat* DoorAnimationCurve;

	UPROPERTY(EditAnywhere, Category = "Animation")
	float OpeningAngle = 90.0f;

	FTimeline DoorTimeline;

	UFUNCTION(BlueprintCallable)
	void OpenDoor();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	FRotator InitialRotation;
	FRotator TargetRotation;

	UFUNCTION()
	void UpdateDoorRotation(float Value);
};
