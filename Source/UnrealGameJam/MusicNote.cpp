// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicNote.h"

// Sets default values
AMusicNote::AMusicNote()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = _Root;
	
	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_MeshComponent->SetupAttachment(_Root);
	
	_BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	_BoxCollider->InitBoxExtent(FVector(50.f));
	_BoxCollider->SetupAttachment(_Root);
	_BoxCollider->SetCollisionProfileName("OverlapAll");
	
}

// Called when the game starts or when spawned
void AMusicNote::BeginPlay()
{
	Super::BeginPlay();
	
}

/*// Called every frame
void AMusicNote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

