// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMPUZZLE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();


	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
	float speed = 20;

	UPROPERTY(EditAnywhere, meta=(MakeEditWidget = true))	
	FVector TargetLocation;



private:

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;


	FVector getDirection();

	FVector fromLocalToWorld(FVector location);
};
