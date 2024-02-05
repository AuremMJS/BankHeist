// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeamBase.h"

// Sets default values
ALaserBeamBase::ALaserBeamBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	leftDuration = FMath::FRandRange(3.0, 5.0);
	rightDuration = FMath::FRandRange(3.0, 5.0);
	leftNodeTimeElapsed = rightNodeTimeElapsed = 0.0f;
}

// Called when the game starts or when spawned
void ALaserBeamBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALaserBeamBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateLaserNodePosition(DeltaTime);
}

void ALaserBeamBase::SetLaserNodeParams(UPARAM(ref) USceneComponent* _leftNode, UPARAM(ref) USceneComponent* _rightNode, UPARAM(ref) const float _startPositionY, UPARAM(ref) const float _endPositionY)
{
	startPositionY = _startPositionY;
	endPositionY = _endPositionY;

	leftNode = _leftNode;
	rightNode = _rightNode;
};

void ALaserBeamBase::UpdateLaserNodePosition(float deltaTime)
{
	SetNodePosition(leftNodeTimeElapsed, leftDuration, leftNode, deltaTime);
	SetNodePosition(rightNodeTimeElapsed, rightDuration, rightNode, deltaTime);
}

void ALaserBeamBase::SetNodePosition(float& timeElapsed, float& duration, USceneComponent* node, float& deltaTime)
{
	float newY = startPositionY * (timeElapsed / duration) + endPositionY * (1 - (timeElapsed / duration));
	if (timeElapsed >= duration)
	{
		int temp = startPositionY;
		startPositionY = endPositionY;
		endPositionY = temp;
		timeElapsed = 0;
	}
	FVector currentLocation = node->GetRelativeLocation();
	currentLocation.Z = newY;
	node->SetRelativeLocation(currentLocation);
	timeElapsed += deltaTime;
}