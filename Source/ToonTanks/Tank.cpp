// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}
void ATank::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
			if (Subsystem && InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}


void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(IA_MoveForward, ETriggerEvent::Triggered, this, &ATank::Move);
		EnhancedInputComponent->BindAction(IA_Turn, ETriggerEvent::Triggered, this, &ATank::Turn);
	}
}



void ATank::Move(const FInputActionValue& Value)
{
	FVector2D InputValue = Value.Get<FVector2D>(); 
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = InputValue.X * Speed * UGameplayStatics::GetWorldDeltaSeconds(this); // UGameplayStatics::GetWorldDeltaSeconds(this) is DeltaTime
	ATank::AddActorLocalOffset(DeltaLocation, true); // True to get blocked when colliding
}

void ATank::Turn(const FInputActionValue& Value)
{
	FVector2D InputValue = Value.Get<FVector2D>();
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = InputValue.X * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	ATank::AddActorLocalRotation(DeltaRotation, true);
}

