// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	this->SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (HasAuthority()) {

		FVector direction = getDirection();
		FVector Location = GetActorLocation();

		float journeyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float journeyTravelled = (Location - GlobalStartLocation).Size();

		if (journeyTravelled >= journeyLength) {
			Swap(GlobalTargetLocation, GlobalStartLocation);
		}

		Location += speed * DeltaTime * direction;
		SetActorLocation(Location);
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

FVector AMovingPlatform::getDirection()
{
	FVector movingDirection = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
	UE_LOG(LogTemp, Warning, TEXT("movingDirection is: %s"), *movingDirection.ToString())
	return movingDirection;
}

FVector AMovingPlatform::fromLocalToWorld(FVector location)
{

	FVector WorldLocation = (FVector)GetWorld()->OriginLocation;



	return FVector();
}
