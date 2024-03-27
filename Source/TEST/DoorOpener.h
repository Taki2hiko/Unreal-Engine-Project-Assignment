// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DoorOpener.generated.h"

UCLASS()
class TEST_API ADoorOpener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorOpener();


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* doorMesh;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UCurveFloat* doorAnimationCurve;

	UPROPERTY(EditAnywhere, Category = "Animation")
	float openingAngle = 90;

	FTimeline doorTimeline;

	UFUNCTION(BlueprintCallable)
	void OpenDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FRotator initialRotation;
	FRotator targetRotation;

	UFUNCTION()
	void UpdateDoorRotation(float Value);
};
