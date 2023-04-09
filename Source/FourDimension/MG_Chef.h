// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MG_Chef.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UMG_DragComponent;
class UPhysicsHandleComponent;

UCLASS()
class FOURDIMENSION_API AMG_Chef : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMG_Chef();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere)
	class UMG_DragComponent* DragComp;

	UPROPERTY(EditAnywhere)
	UPhysicsHandleComponent* PhyHandleComp;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PickObject();
	void ReleaseObject();

};
