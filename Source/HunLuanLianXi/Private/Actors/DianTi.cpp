// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DianTi.h"

// Sets default values
ADianTi::ADianTi()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ADianTi::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADianTi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

