// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "DianTi.generated.h"

UCLASS()
class HUNLUANLIANXI_API ADianTi : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADianTi();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Dianti")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Dianti")
	UBoxComponent* TriggerBox;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
