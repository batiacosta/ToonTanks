// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
	
private:

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Components")
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Movement")
	float Speed = 200.f;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Movement")
	float TurnRate = 200.f;
	
	void Move(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	class UInputAction* IA_MoveForward;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	class UInputAction* IA_Turn;
	
};
