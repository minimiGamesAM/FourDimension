// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_DragComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"


// Sets default values for this component's properties
UMG_DragComponent::UMG_DragComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UPhysicsHandleComponent* UMG_DragComponent::GetPhysicsHandleComp(AActor* FromActor)
{
	if (FromActor)
	{
		return FromActor->FindComponentByClass<UPhysicsHandleComponent>();
	}
	return nullptr;
}

bool UMG_DragComponent::BeginDrag()
{
	AActor* MyOwner = GetOwner();

	UPhysicsHandleComponent* PhysHandleComp = GetPhysicsHandleComp(MyOwner);

	if (!PhysHandleComp)
	{
		return false;
	}

	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);

	FVector EyeLocation;
	FRotator EyeRotation;

	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector End(EyeLocation + (EyeRotation.Vector() * 500.0f));

	FHitResult Hit;
	bool bBlocking = GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);

	FColor LineColor = bBlocking ? FColor::Green : FColor::Red;

	if (bBlocking)
	{
		End = Hit.ImpactPoint;
	}

	float Radius = 30.0f;
	DrawDebugSphere(GetWorld(), End, Radius, 32, LineColor, false, 2.0f);
	DrawDebugLine(GetWorld(), EyeLocation, End, LineColor, false, 2.0f);

	if (bBlocking)
	{
		OnGrabObject.Broadcast(nullptr, Hit.GetComponent(), Hit.ImpactPoint);

		LocalRot = MyOwner->GetTransform().InverseTransformRotation(Hit.GetActor()->GetActorRotation().Quaternion());
		LocalPos = MyOwner->GetTransform().InverseTransformPosition(Hit.ImpactPoint);
		
		
		PhysHandleComp->GrabComponentAtLocationWithRotation(Hit.GetComponent(),
															NAME_None,
															Hit.ImpactPoint,
															Hit.GetActor()->GetActorRotation());

	}

	PossesObject = bBlocking;

	return bBlocking;
}

void UMG_DragComponent::EndDrag()
{
	
}

// Called when the game starts
void UMG_DragComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMG_DragComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent* PhysHandleComp = GetPhysicsHandleComp(GetOwner());

	if (PhysHandleComp)
	{
		FVector Pos = GetOwner()->GetTransform().TransformPosition(LocalPos);
		FQuat4d Rot = GetOwner()->GetTransform().TransformRotation(LocalRot);

		PhysHandleComp->SetTargetLocation(Pos);
		PhysHandleComp->SetTargetRotation(Rot.Rotator());
	}
}

