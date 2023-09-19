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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> _Root;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> NoteOutline;

	//Note hit vars
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> NoteHitCollider;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	FVector NoteHitPosition;

	//Note miss vars
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> NoteMissCollider;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="NoteDetails", meta = (AllowPrivateAccess = "true"))
	FVector NoteMissPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="NoteDetails", meta=(AllowPrivateAccess = "true"))
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

	//Possible BlueprintNativeEvent for sending scores?
	UFUNCTION()
	float HitNote();
	//virtual void OnBeginOverlap 
};
