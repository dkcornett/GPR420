// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "Misc/App.h"
#include "EnemyMovement.generated.h"

class UPawnMovementComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PACSNAKE_API UEnemyMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyMovement();

	//movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UPawnMovementComponent* PawnMovementComponent;

	//referenced this for doing movement fully in scripting
	//https://answers.unrealengine.com/questions/419211/how-to-move-an-actor-in-c.html
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FVector EnemyLocation;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float speed;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//handles forward movement, referenced from project 1 and 2
	void MoveForward(float Val);

	//handles right movement, referenced from project 1 and 2
	void MoveRight(float Val);


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
