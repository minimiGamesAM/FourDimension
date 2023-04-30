// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MG_TuboBasico.generated.h"

class UStaticMeshComponent;
class UPhysicsConstraintComponent;

UCLASS()
class FOURDIMENSION_API AMG_TuboBasico : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMG_TuboBasico();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Bodies")
	float Masa = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Connection")
	float Stiffness = 123.0f;

	UPROPERTY(EditAnywhere, Category = "Connection")
	float AngularSwingLimite1 = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Connection")
	float AngularSwingLimite2 = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Bodies")
	TArray<UStaticMeshComponent*> MeshCompones;

	UPROPERTY(VisibleAnywhere, Category = "Connection")
	TArray<UPhysicsConstraintComponent*> ConstraintCompones;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
