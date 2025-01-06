// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DianTi_Button.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SomeGameMode/PeopPlayController.h"


ADianTi_Button::ADianTi_Button()
{
	
	QuyuJiance = false;

	
}

void ADianTi_Button::BeginPlay()
{
	Super::BeginPlay();

	

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this,&ADianTi_Button::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ADianTi_Button::OnOverlapEnd);

}

void ADianTi_Button::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	//APeopPlayController* PlayerController = Cast<APeopPlayController>(UGameplayStatics::GetPlayerController(this, 0));


	//PlayerController->DiantiQuyuJiance(true);


	//PlayerIn.Broadcast(true);
}

void ADianTi_Button::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	//APeopPlayController* PlayerController = Cast<APeopPlayController>(UGameplayStatics::GetPlayerController(this, 0));


	//PlayerController->DiantiQuyuJiance(false);
}
