// Fill out your copyright notice in the Description page of Project Settings.

#include "AirSim.h"
#include "PhysicsEngine/PhysicsConstraintActor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "ConstraintResetter.h"


// Sets default values for this component's properties
UConstraintResetter::UConstraintResetter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UConstraintResetter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	this->startPos = this->GetOwner()->GetActorLocation();
	this->startOrient = this->GetOwner()->GetActorRotation();
	auto c = (APhysicsConstraintActor*)(this->GetOwner());
	this->initialConstraint1 = c->GetConstraintComp()->ConstraintActor1;
}

void UConstraintResetter::reset()
{
	this->GetOwner()->SetActorLocation(this->startPos, false, nullptr, ETeleportType::TeleportPhysics);
	this->GetOwner()->SetActorRotation(this->startOrient, ETeleportType::TeleportPhysics);
	auto c = (APhysicsConstraintActor*)(this->GetOwner());
	c->GetConstraintComp()->SetConstrainedComponents(
		this->initialConstraint1->GetRootPrimitiveComponent(),
		FName(),
		c->GetConstraintComp()->ConstraintActor2->GetRootPrimitiveComponent(),
		FName()
	);
}


// Called every frame
void UConstraintResetter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

