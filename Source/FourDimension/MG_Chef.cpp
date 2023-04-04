// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_Chef.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMG_Chef::AMG_Chef()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void AMG_Chef::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMG_Chef::MoveForward(float Value)
{
	FRotator ControlRot(GetControlRotation());
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}

void AMG_Chef::MoveRight(float Value)
{

	FRotator ControlRot(GetControlRotation());
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	//X = Forward (Red)
	//Y = Right (Green)
	//Z = Up (Blue)

	FVector RightVector(FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y));
	AddMovementInput(RightVector, Value);
}

// Called every frame
void AMG_Chef::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMG_Chef::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoverAdelante", this, &AMG_Chef::MoveForward);
	PlayerInputComponent->BindAxis("MoverLados", this, &AMG_Chef::MoveRight);

	PlayerInputComponent->BindAxis("Girar", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Mirar", this, &APawn::AddControllerPitchInput);

}

