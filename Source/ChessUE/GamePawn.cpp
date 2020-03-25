// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePawn.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"


// Sets default values
AGamePawn::AGamePawn()
{	
	PScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = PScene;

	PCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("camera"));
	PCamera->SetupAttachment(RootComponent);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void AGamePawn::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AGamePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("ClickChessPiece", EInputEvent::IE_Pressed, this, &AGamePawn::ClickChessPiece);
	PlayerInputComponent->BindAxis("MoveChessPiece", this, &AGamePawn::MoveChessPiece);
}

void AGamePawn::ClickChessPiece()
{
	//debug
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}

void AGamePawn::MoveChessPiece(float a)
{
	//debug
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("fff"));
}

