// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicNoteCollector.h"
#include "MainChar.h"

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
	Super::BeginPlay();
}

void AMusicNoteCollector::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                       const FHitResult& SweepResult)
{
	if (OverlappedComponent == NoteHitCollider)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Can collide with note"));
		AvailableNotes.Add(OtherActor);
	}

	if (OverlappedComponent == NoteMissCollider)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Turquoise, TEXT("Note Missed"));
		AvailableNotes.Remove(OtherActor);
		OtherActor->Destroy();
	}
}

void AMusicNoteCollector::HitNote(float &score_out, FVector &location_out)
{
	if (AvailableNotes.Num() <= 0)
	{
		return;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("HIT NOTE"));
	
	FVector OutlinePosition = NoteOutline->GetComponentLocation();
	AActor* Note = AvailableNotes.Pop(true);
	FVector NotePosition = Note->GetActorLocation();
	float distanceFromOutline = (NotePosition - OutlinePosition).Length();
	float score = 0.f;

	if(distanceFromOutline >= 500.f) //okay
	{
		score = 25.f;
	}
	else if(distanceFromOutline >= 200.f && distanceFromOutline < 499.f) //great
	{
		score = 50.f;
	}
	else if(distanceFromOutline < 250.f) //perfect
	{
		score = 100.0f;
	}
	
	Note->Destroy();
	score_out = score;
	location_out = NotePosition;
}

