// Fill out your copyright notice in the Description page of Project Settings.

#include "AirSim.h"
#include "ActorReset.h"


// Sets default values for this component's properties
UActorReset::UActorReset()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorReset::BeginPlay()
{
	Super::BeginPlay();

	// ...

	this->startPos = this->GetOwner()->GetActorLocation();
	this->startOrient = this->GetOwner()->GetActorRotation();
}

void UActorReset::reset()
{
	this->GetOwner()->SetActorLocation(this->startPos, false, nullptr, ETeleportType::TeleportPhysics);
	this->GetOwner()->SetActorRotation(this->startOrient, ETeleportType::TeleportPhysics);
}

// Called every frame
void UActorReset::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

