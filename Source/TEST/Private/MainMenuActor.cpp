// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainMenuActor::AMainMenuActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainMenuActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainMenuActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainMenuActor::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainLevel");
}

void AMainMenuActor::MainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void AMainMenuActor::ExitGame()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController) {
		PlayerController->ConsoleCommand("quit");
	}

}

