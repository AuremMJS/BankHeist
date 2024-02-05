// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserBeamBase.generated.h"

UCLASS()
class BANKHEIST_API ALaserBeamBase : public AActor
{
	GENERATED_BODY()
private:
	float leftDuration;
	float rightDuration;
	float leftNodeTimeElapsed;
	float rightNodeTimeElapsed;
	USceneComponent* leftNode;
	USceneComponent* rightNode;
	float startPositionY;
	float endPositionY;
	
	void SetNodePosition(float& timeElapse, float& duration, USceneComponent* node, float& deltaTime);
public:	
	// Sets default values for this actor's properties
	ALaserBeamBase();

	UFUNCTION(BlueprintCallable)
	void SetLaserNodeParams(UPARAM(ref) USceneComponent* _leftNode, UPARAM(ref) USceneComponent* _rightNode, UPARAM(ref) const float _startPositionY, UPARAM(ref) const float _endPositionY);
	void UpdateLaserNodePosition(float deltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
