// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_Stove.h"
#include "MG_GameplayInterface.h"

// Sets default values
AMG_Stove::AMG_Stove()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//InteractionComp = CreateDefaultSubobject<UMG_InteractComponent>("InteractionComp");

}

void AMG_Stove::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	StoveMeshComp = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
}

void AMG_Stove::StoveTouched(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (OtherActor->Implements<UMG_GameplayInterface>())
		{
			IMG_GameplayInterface::Execute_Interact(OtherActor, this);
		}
	}
}


// Called when the game starts or when spawned
void AMG_Stove::BeginPlay()
{
	Super::BeginPlay();

	if (StoveMeshComp)
	{
		StoveMeshComp->OnComponentBeginOverlap.AddDynamic(this, &AMG_Stove::StoveTouched);
	}
}

// Called every frame
void AMG_Stove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

