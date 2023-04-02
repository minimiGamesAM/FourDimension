// Fill out your copyright notice in the Description page of Project Settings.


#include "Personaje.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MG_DragComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values
APersonaje::APersonaje()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    DragComp = CreateDefaultSubobject<UMG_DragComponent>("DragComp");
    PhyHandleComp = CreateDefaultSubobject<UPhysicsHandleComponent>("PhyHandleComp");
}

void APersonaje::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    if (DragComp)
    {
        DragComp->OnGrabObject.AddDynamic(this, &APersonaje::SetPhysicsHandle);
    }
}

// Called when the game starts or when spawned
void APersonaje::BeginPlay()
{
	Super::BeginPlay();
	
    TArray<UActorComponent*> comps;

    this->GetComponents(comps);

    for (int i = 0; i < comps.Num(); ++i) //Because there may be more components
    {
        USpringArmComponent* thisCompP = Cast<USpringArmComponent>(comps[i]); //try to cast to static mesh component
        if (thisCompP)
        {
            SpringArmComp = thisCompP;
        }

        UCameraComponent* thisCompS = Cast<UCameraComponent>(comps[i]); //try to cast to static mesh component
        if (thisCompS)
        {
            CameraComp = thisCompS;
        }
    }
}

// Called every frame
void APersonaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (DragComp && PhyHandleComp && DragComp->PossesObject)
    {

        APawn* MyPawn = Cast<APawn>(this);

        //FVector Pos = MyPawn->GetTransform().TransformVector(DragComp->LocalPos);

        //DrawDebugPoint(GetWorld(), Pos, 1, FColor::Green, false, 1.0);
        PhyHandleComp->SetTargetLocation(DragComp->LocalPos + GetActorLocation());
    }
}

// Called to bind functionality to input
void APersonaje::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
    PlayerInputComponent->BindAxis("MoverAdelante", this, &APersonaje::MoveForward);
    PlayerInputComponent->BindAxis("MoverLados", this, &APersonaje::MoveRight);
    PlayerInputComponent->BindAxis("EjercerFuerza", this, &APersonaje::EjercerFuerza);

    PlayerInputComponent->BindAxis("Girar", this, &APersonaje::AddControllerYawInput);
    PlayerInputComponent->BindAxis("Mirar", this, &APersonaje::AddControllerPitchInput );

    PlayerInputComponent->BindAction("Pick", IE_Pressed, this, &APersonaje::PickObject);

}

void APersonaje::SetPhysicsHandle(AActor* InstigatorActor, UPrimitiveComponent* CompToDrag, FVector Location)
{
    PhyHandleComp->GrabComponentAtLocation(CompToDrag, NAME_None, Location);
}

void APersonaje::PickObject()
{
    DragComp->BeginDrag();
}

void APersonaje::ReleaseObject()
{
}


void APersonaje::EjercerFuerza(float Val)
{
    if (Val != 0.f)
    {
        FVector v(PointOfAttraction - GetActorLocation());
        float distance = v.Length();
        v.Normalize();

        float force = MasaActor * MasaAtractor / pow(distance, 2);

        AddMovementInput(v, Val * force, true);
    }
}

void APersonaje::MoveForward(float Val)
{
    // Move at 100 units per second forward or backward
    //CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
    if (Val != 0.f)
    {
        if (Controller)
        {
            FRotator const ControlSpaceRot = Controller->GetControlRotation();

            // transform to world space and add it
            AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
        }
    }
}

void APersonaje::MoveRight(float Val)
{
    if (Val != 0.f)
    {
        if (Controller)
        {
            FRotator const ControlSpaceRot = Controller->GetControlRotation();

            // transform to world space and add it
            AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
        }
    }
    // Move at 100 units per second right or left
    //CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}


