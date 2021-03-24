// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "TimerManager.h"
#include "FPSCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class AFPSProjectile;
class AFPSChargedProjectile;
class USoundBase;
class UAnimSequence;


UCLASS()
class AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	/** Pawn mesh: 1st person view  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mesh")
	USkeletalMeshComponent* Mesh1PComponent;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMeshComponent;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComponent;

public:
	AFPSCharacter();

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category="Projectile")
	TSubclassOf<AFPSProjectile> ProjectileClass;

	/** Charged Projectile class to spawn*/
	UPROPERTY(EditDefaultsOnly, Category="Projectile")
	TSubclassOf<AFPSChargedProjectile> ChargedProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	USoundBase* FireSound;

	/** Particle system for the explosion */
//	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
//		UParticleSystem* ExplosionEffect;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	UAnimSequence* FireAnimation;

	UPROPERTY(BlueprintReadOnly)
	float AmountCharged;

	UPROPERTY(BlueprintReadOnly)
	float TimeToCoolDown;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (ClampMin = "0.0"))
	float MaxCooldown = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (ClampMin = "0.1", ClampMax = "1.0"))
	float ChargeTime;

	virtual void Tick(float DeltaTime) override;

protected:
	
	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable, CallInEditor)
	void Fire();

	/** Charges the charged projectile. */
	UFUNCTION(BlueprintCallable, CallInEditor)
	void Charge();

	//Timer delegate stuff from video
	void timerDelegate();

	/** Fires the charged projectile. */
	//fixed function finding bug from this https://answers.unrealengine.com/questions/865226/bindufunction-failed-to-find-function.html?sort=oldest 
	UFUNCTION(BlueprintCallable, CallInEditor)
	void FireCharged();

	/** Handles moving forward/backward */
	UFUNCTION(BlueprintCallable, CallInEditor)
	void MoveForward(float Val);

	/** Handles strafing movement, left and right */
	UFUNCTION(BlueprintCallable, CallInEditor)
	void MoveRight(float Val);


	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	bool IsCharging;

	bool IsCoolDown;

	float scale;

	//const FTimer CoolDownTimer;

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1PComponent; }

	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return CameraComponent; }

	FHttpModule* Http;

	/* The actual HTTP call */
	UFUNCTION() void MyHttpCall();

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);


};

