// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PeopPlayController.generated.h"


class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ADianTi_Button;
class UEnhancedInputLocalPlayerSubsystem;
class UEnhancedInputComponent;

/**
 * 
 */
UCLASS()
class HUNLUANLIANXI_API APeopPlayController : public APlayerController
{
	GENERATED_BODY()
	

	

	virtual void BeginPlay() override;

protected:

	UEnhancedInputLocalPlayerSubsystem* Subsystem;
	UEnhancedInputComponent* Input;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Dianti")
	ADianTi_Button* DianTiButton;


	bool DianTiButton_Quyu;

	UPROPERTY(EditDefaultsOnly)
	UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly)
	UInputMappingContext* InputMapping_DianTi;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_Move;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_Jump;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_E;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_EDianti;

	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& Value);

	void isJump(const FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);
	void EJian(const FInputActionValue& Value);
	void EJian_DianTi(const FInputActionValue& Value);


public:
	UFUNCTION(BlueprintCallable, Category = "Dianti")
	void DiantiQuyuJiance(bool IsQuyu);
};
