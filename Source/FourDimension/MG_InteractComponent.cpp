// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_InteractComponent.h"

// Sets default values for this component's properties
UMG_InteractComponent::UMG_InteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMG_InteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMG_InteractComponent::Interact()
{
	//GetOwner()
}

void UMG_InteractComponent::EndInteract()
{
	
}

// Called every frame
void UMG_InteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

