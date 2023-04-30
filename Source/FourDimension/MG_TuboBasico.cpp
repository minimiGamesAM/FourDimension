// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_TuboBasico.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
AMG_TuboBasico::AMG_TuboBasico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMG_TuboBasico::BeginPlay()
{
	Super::BeginPlay();

	for (UStaticMeshComponent* Mesh : MeshCompones)
	{
		Cast<UPrimitiveComponent>(Mesh)->SetMassOverrideInKg(NAME_None, Masa, true);
	}

	for (UPhysicsConstraintComponent* ConstraintComp : ConstraintCompones)
	{
		FConstraintInstance ConstraintInstance = ConstraintComp->ConstraintInstance;
		ConstraintInstance.SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Limited, AngularSwingLimite1);
		ConstraintInstance.SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Limited, AngularSwingLimite2);

		ConstraintInstance.SetSoftSwingLimitParams(true, Stiffness, 1.0f, 0.0f, 1.0f);

		ConstraintComp->ConstraintInstance = ConstraintInstance;
	}
}

void AMG_TuboBasico::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	TArray<UActorComponent*> comps;
	this->GetComponents(comps);

	for (int i = 0; i < comps.Num(); ++i) //Because there may be more components
	{
		UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(comps[i]); //try to cast to static mesh component

		if (MeshComp && MeshComp->IsSimulatingPhysics())
		{
			MeshCompones.Add(MeshComp);
		}

		UPhysicsConstraintComponent* ConstraintComp = Cast<UPhysicsConstraintComponent>(comps[i]); //try to cast to static mesh component

		if (ConstraintComp)
		{
			ConstraintCompones.Add(ConstraintComp);
		}
	}

}


// Called every frame
void AMG_TuboBasico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//for (UStaticMeshComponent* Mesh : MeshCompones)
	//{
	//	FString Mensaje = FString::Printf(TEXT("Masa : %f"), Mesh->GetMass());
	//	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Blue, Mensaje);
	//}
	//
	//for (UPhysicsConstraintComponent* ConstraintComp : ConstraintCompones)
	//{
	//	float StiffnessSuave = ConstraintComp->ConstraintInstance.GetSoftSwingLimitStiffness();
	//	FString Mensaje = FString::Printf(TEXT("Stiffness : %f"), StiffnessSuave);
	//	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, Mensaje);
	//}
}

