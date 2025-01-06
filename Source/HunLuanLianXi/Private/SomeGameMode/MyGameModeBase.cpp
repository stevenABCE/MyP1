// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameMode/MyGameModeBase.h"
#include "Characters/MyCharacter.h"


AMyGameModeBase::AMyGameModeBase()
{

	DefaultPawnClass = AMyCharacter::StaticClass();
}
