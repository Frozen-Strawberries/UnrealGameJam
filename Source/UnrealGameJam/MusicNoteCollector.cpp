// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicNoteCollector.h"

#include "Chaos/GeometryParticlesfwd.h"

// Sets default values
AMusicNoteCollector::AMusicNoteCollector()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = _Root;
	//_Root->SetRelativeLocation(FVector(250.f, 0.f, 0.f));

	NoteOutline = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	NoteOutline->SetupAttachment(_Root);
	NoteOutline->SetCollisionProfileName("NoCollision");

	NoteHitCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Note Hit Collider"));
	NoteHitCollider->InitBoxExtent(FVector(250.f, 25.f, 25.f));
	NoteHitCollider->SetupAttachment(_Root);
	NoteHitCollider->SetCollisionProfileName("Trigger");
	NoteHitCollider->OnComponentBeginOverlap.AddDynamic(this, &AMusicNoteCollector::BeginOverlap);

	NoteMissCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Note Miss Collider"));
	NoteMissCollider->InitBoxExtent(FVector(25.f, 25.f, 25.f));
	NoteMissCollider->SetupAttachment(_Root);
	NoteMissCollider->SetCollisionProfileName("Trigger");
	NoteMissCollider->OnComponentBeginOverlap.AddDynamic(this, &AMusicNoteCollector::BeginOverlap);
}

// Called when the game starts or when spawned
void AMusicNoteCollector::BeginPlay()
{
	/*NoteHitCollider->SetRelativeLocation(NoteHitPosition);
	NoteMissCollider->SetRelativeLocation(NoteMissPosition);*/
	Super::BeginPlay();
}

void AMusicNoteCollector::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                       const FHitResult& SweepResult)
{
	if (OverlappedComponent == NoteHitCollider)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Can collide with note"));
		AvailableNotes.Add(OtherActor);
	}

	if (OverlappedComponent == NoteMissCollider)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Turquoise, TEXT("Note Missed"));
		AvailableNotes.Remove(OtherActor);
		OtherActor->Destroy();
	}
}

float AMusicNoteCollector::HitNote()
{
	//TODO: Calculate note tolerances
	if (AvailableNotes.Num() <= 0)
	{
		return 0.f;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("HIT NOTE"));

	FVector PlayerPosition = GetParentActor()->GetActorLocation();
	AActor* Note = AvailableNotes.Pop(true);
	FVector NotePosition = Note->GetActorLocation();
	float distanceFromOutline = (NotePosition - PlayerPosition).Length();
	Note->Destroy();

	float score = 0.f;
	return score;
}

// Called every frame
/*
void AMusicNoteCollector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
*/
