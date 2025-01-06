// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}



void AMyCharacter::Move(const FVector2D& MovementVector)
{
	if (MovementVector.X != 0)
	{
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}

	if (MovementVector.Y != 0)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	}
	
}

void AMyCharacter::isJump(const bool& IsJump)
{
	if (IsJump)
	{
		Jump();
	}
	else
	{
		StopJumping();
	}
}

void AMyCharacter::Look(const FVector2D& MouseValue)
{
	if (MouseValue.X != 0)
	{
		AddControllerYawInput(MouseValue.X);
	}
	
	if (MouseValue.Y != 0)
	{
		AddControllerPitchInput(MouseValue.Y);
	}

	
}

