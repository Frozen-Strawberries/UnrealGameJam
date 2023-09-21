// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteCollector.h"

// Sets default values for this component's properties
UNoteCollector::UNoteCollector()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	_BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	_BoxCollider->InitBoxExtent(FVector(25.f));
	_BoxCollider->SetCollisionProfileName("Trigger");
}


// Called when the game starts
void UNoteCollector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNoteCollector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

