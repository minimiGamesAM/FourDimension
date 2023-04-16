// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_Pot.h"

// Sets default values
AMG_Pot::AMG_Pot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMG_Pot::Interact_Implementation(AActor* InstigatorPawn)
{
	if (PotMeshComp)
	{
		PotMeshComp->SetScalarParameterValueOnMaterials("TimeToHeat", GetWorld()->TimeSeconds);
		PotMeshComp->SetScalarParameterValueOnMaterials("RateOfHeat", HeatRate);
	}
}

void AMG_Pot::EndInteract_Implementation(AActor* InstigatorPawn)
{
	
}

void AMG_Pot::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PotMeshComp = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
}

// Called when the game starts or when spawned
void AMG_Pot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMG_Pot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

