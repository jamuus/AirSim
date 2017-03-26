// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "ConstraintResetter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIRSIM_API UConstraintResetter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UConstraintResetter();

	void reset();

	FVector startPos;
	FRotator startOrient;
	AActor* initialConstraint1;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
