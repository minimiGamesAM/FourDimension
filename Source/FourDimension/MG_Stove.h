// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MG_Stove.generated.h"

//class UMG_InteractComponent;
class UStaticMeshComponent;

UCLASS()
class FOURDIMENSION_API AMG_Stove : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMG_Stove();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StoveMeshComp = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void StoveTouched(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UPROPERTY(VisibleAnywhere)
	//UMG_InteractComponent* InteractionComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
		
	virtual void PostInitializeComponents() override;
};
