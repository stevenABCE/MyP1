// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class HUNLUANLIANXI_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMyCharacter();

protected:

	virtual void BeginPlay() override;




public:	

	virtual void Tick(float DeltaTime) override;


	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FVector2D& MovementVector);

	void isJump(const bool& IsJump);

	void Look(const FVector2D& MouseValue);

};
