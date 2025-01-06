// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameMode/PeopPlayController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Characters/MyCharacter.h"
#include "Actors/DianTi_Button.h"


void APeopPlayController::BeginPlay()
{
	bShowMouseCursor = true;

	bEnableClickEvents = true;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
	SetupInputComponent();
	
	//DianTiButton->PlayerIn.AddDynamic(this, &APeopPlayController::DiantiQuyuJiance);
}

void APeopPlayController::SetupInputComponent()
{
	Super::SetupInputComponent();

	Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(InputMapping);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping,0);

	Input = Cast<UEnhancedInputComponent>(InputComponent);
	Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APeopPlayController::Move);
	Input->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &APeopPlayController::isJump);
	Input->BindAction(IA_Jump, ETriggerEvent::Completed, this, &APeopPlayController::isJump);
	Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APeopPlayController::Look);
	Input->BindAction(IA_E, ETriggerEvent::Started, this, &APeopPlayController::EJian);
	Input->BindAction(IA_EDianti, ETriggerEvent::Started, this, &APeopPlayController::EJian_DianTi);
	
	
}


void APeopPlayController::Move(const FInputActionValue& Value)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EJian"));
	AMyCharacter* Charactera = Cast<AMyCharacter>(GetPawn());

	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Charactera)
	{
		Charactera->Move(MovementVector);
	}
}

void APeopPlayController::isJump(const FInputActionValue& Value)
{

	AMyCharacter* Charactera = Cast<AMyCharacter>(GetPawn());

	Charactera->isJump(Value.Get<bool>());
}

void APeopPlayController::Look(const FInputActionValue& Value)
{
	AMyCharacter* Charactera = Cast<AMyCharacter>(GetPawn());

	Charactera->Look(Value.Get<FVector2D>());

}

void APeopPlayController::EJian(const FInputActionValue& Value)
{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EJian"));


}

void APeopPlayController::EJian_DianTi(const FInputActionValue& Value)
{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("InDianTi"));


}

void APeopPlayController::DiantiQuyuJiance(bool IsQuyu)
{

	if (IsQuyu == true)
	{
		//Input->BindAction(IA_EDianti, ETriggerEvent::Triggered, this, &APeopPlayController::EJian_DianTi);
		Subsystem->AddMappingContext(InputMapping_DianTi, 1);
	}
	else
	{
		Subsystem->RemoveMappingContext(InputMapping_DianTi);
		//Input->BindAction(IA_E, ETriggerEvent::Triggered, this, &APeopPlayController::EJian);
	}
}



