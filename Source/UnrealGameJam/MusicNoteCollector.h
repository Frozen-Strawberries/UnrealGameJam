// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MusicNoteCollector.generated.h"

UCLASS()
class UNREALGAMEJAM_API AMusicNoteCollector : public AActor
{
	GENERATED_BODY()

	//General note vars

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> _Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> NoteOutline;

	//Note hit vars

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> NoteHitCollider;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	FVector NoteHitPosition;*/

	//Note miss vars

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> NoteMissCollider;

	/*
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	FVector NoteMissPosition;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NoteDetails", meta=(AllowPrivateAccess = "true"))
	TArray<AActor*> AvailableNotes;

public:
	// Sets default values for this actor's properties
	AMusicNoteCollector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	                  AActor* OtherActor,
	                  UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex,
	                  bool bFromSweep,
	                  const FHitResult& SweepResult);

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void HitNote(float &score_out, FVector &location_out);

	/*UFUNCTION(Blueprint)
	void DestroyNote(AActor* NoteToDestroy);*/
};
