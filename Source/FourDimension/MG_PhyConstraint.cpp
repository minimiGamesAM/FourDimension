// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_PhyConstraint.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
AMG_PhyConstraint::AMG_PhyConstraint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Imanes
//https://www.youtube.com/watch?v=--xR0aQ2rB0&list=PLEp7216xGGII6tRXPfxbPGPec1VWRWDSO&index=10&ab_channel=Lusiogenic

	//Jump pad
//https://www.youtube.com/watch?v=AHZcFyHLGqQ&list=PLEp7216xGGII6tRXPfxbPGPec1VWRWDSO&index=17&ab_channel=Lusiogenic

	//Trampolin
//https://www.youtube.com/watch?v=iJv7gmNwWMM&list=PLEp7216xGGII6tRXPfxbPGPec1VWRWDSO&index=22&ab_channel=Lusiogenic

	//cuerda with physic constraints
//https://www.youtube.com/watch?v=hEMcr98cDJE&list=PLEp7216xGGII6tRXPfxbPGPec1VWRWDSO&index=11&ab_channel=Lusiogenic
}

// Called when the game starts or when spawned
void AMG_PhyConstraint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMG_PhyConstraint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PhysicsConstraintComp)
	{
		//float Restitucion = PhysicsConstraintComp->ConstraintInstance.GetSoftTwistLimitRestitution();
		//float ContDis = PhysicsConstraintComp->ConstraintInstance.GetSoftTwistLimitContactDistance();
		//FString Mensaje = FString::Printf(TEXT("Restitucion : %f, ContDis : %f"), Restitucion, ContDis);
		//GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, Mensaje);
	}
}

void AMG_PhyConstraint::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PhysicsConstraintComp = Cast<UPhysicsConstraintComponent>(GetComponentByClass(UPhysicsConstraintComponent::StaticClass()));

}
