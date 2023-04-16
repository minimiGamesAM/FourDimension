// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MG_GameplayInterface.h"
#include "MG_Pot.generated.h"

UCLASS()
class FOURDIMENSION_API AMG_Pot : public AActor, public IMG_GameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMG_Pot();

	void Interact_Implementation(AActor* InstigatorPawn);

	void EndInteract_Implementation(AActor* InstigatorPawn);

protected:
	UPROPERTY(EditAnywhere, Category = "Heat")
	float HeatRate = 0.0f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PotMeshComp = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
