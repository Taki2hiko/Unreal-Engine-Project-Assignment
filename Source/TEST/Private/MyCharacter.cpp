// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionSound = nullptr; // Initialize the sound variable
	AutoPossessPlayer = EAutoReceiveInput::Disabled; // Do not possess player
	bCollisionSoundPlayed = false;  // Initialize the flag
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap); // Set collision response for custom channel to overla
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle FTH;
	GetWorldTimerManager().SetTimer(FTH, this, &AMyCharacter::CountDownTimer, 1.0, true, 0.0);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (CollisionSound && !bCollisionSoundPlayed)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CollisionSound, GetActorLocation());
		bCollisionSoundPlayed = true; // Set the flag to true after playing the sound
	}
}


void AMyCharacter::CountDownTimer()
{
	if (Seconds != 0)
	{
		--Seconds;
	}
	else
	{
		if (Minutes == 0)
		{
			GameOver();
		}
		else
		{
			--Minutes;
			Seconds = 59;
		}
	}
}

void AMyCharacter::GameOver()
{
	FOutputDeviceNull null;
	const FString command = FString::Printf(TEXT("GameOverWidget"));
	this->CallFunctionByNameWithArguments(*command, null, NULL, true);
}

