// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DianTi.h"
#include "DianTi_Button.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerIn, bool,IsIn);


/**
 * 
 */
UCLASS()
class HUNLUANLIANXI_API ADianTi_Button : public ADianTi
{
	GENERATED_BODY()

	ADianTi_Button();

	void BeginPlay() override;

	bool IsPress;
	bool QuyuJiance;
public:
	UPROPERTY(BlueprintAssignable,Category="Dianti")
	FOnPlayerIn PlayerIn;
protected:
		
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};
