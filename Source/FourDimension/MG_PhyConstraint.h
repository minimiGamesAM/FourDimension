// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MG_PhyConstraint.generated.h"

class UPhysicsConstraintComponent;

UCLASS()
class FOURDIMENSION_API AMG_PhyConstraint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMG_PhyConstraint();

protected:
	UPROPERTY(EditAnywhere)
	UPhysicsConstraintComponent* PhysicsConstraintComp = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
