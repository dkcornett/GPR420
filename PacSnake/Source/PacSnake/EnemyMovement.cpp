// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMovement.h"

// Sets default values for this component's properties
UEnemyMovement::UEnemyMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//	PawnMovementComponent = GetOwner()->

			//starting values
	EnemyLocation = GetOwner()->GetActorLocation();
	speed = 60.0f;

}


// Called when the game starts
void UEnemyMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UEnemyMovement::MoveForward(float Val)
{
	//	EnemyLocation.ForwardVector += speed * DeltaTime;
}

void UEnemyMovement::MoveRight(float Val)
{
	//	EnemyLocation.RightVector += speed * DeltaTime;
}


// Called every frame
void UEnemyMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// ...
//	EnemyLocation.X += speed * DeltaTime;
//	EnemyLocation.Y += speed * DeltaTime;
//	GetOwner()->GetTransform()->SetLocation(EnemyLocation);			///->GetActorTransform().SetLocation(EnemyLocation);

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

