// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
private:
	// VisibleAnywhere, EditAnywhere, values can be modified in their blueprints and the instances of those blueprints
	// VisibleInstanceOnly, EditInstanceOnly, values can be modifie or visible only in the instances of the blueprint
	// VisibleDefaultOnly, EditDefaultsOnly, values can be visible or modified only on the blueprint, not the instances
	// BlueprintReadWrite, BlueprintReadOnly, values can be modified or read-only on blueprints event graph
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"), VisibleAnywhere, Category="Components")
	class UCapsuleComponent* CapsuleComp; // Forward declaration to avoid unnecessary headers UCapsule is already included in APawn class
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"), VisibleAnywhere, Category="Components")
	UStaticMeshComponent* BaseMesh; // header or forward declaration are not needed for UStaticMeshComponent since it comes with Actor class
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"), VisibleAnywhere, Category="Components")
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"), VisibleAnywhere, Category="Components")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	float Speed;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
