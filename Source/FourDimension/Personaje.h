// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Personaje.generated.h"

class UMG_DragComponent;
class UPhysicsHandleComponent;

UCLASS()
class FOURDIMENSION_API APersonaje : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APersonaje();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
	class UMG_DragComponent* DragComp;

	UPROPERTY(EditAnywhere)
	UPhysicsHandleComponent* PhyHandleComp;

	virtual void PostInitializeComponents() override;
public:

	UFUNCTION(BlueprintCallable)
	void setPointOfAttraction(FVector pos)
	{
		PointOfAttraction = pos;
	}

	UPROPERTY(EditAnywhere)
	float MasaActor = 10;

	UPROPERTY(EditAnywhere)
	float MasaAtractor = 100;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Input functions
	void MoveForward(float Val);
	void MoveRight(float Val);

	void EjercerFuerza(float Val);

	void PickObject();
	void ReleaseObject();

	UFUNCTION()
	void SetPhysicsHandle(AActor* InstigatorActor, UPrimitiveComponent* CompToDrag, FVector Location);
	
private:
	FVector PointOfAttraction;
	
};
