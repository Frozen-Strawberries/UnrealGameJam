// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "kismet/GameplayStatics.h"
#include "AwakeAudioPlayer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALGAMEJAM_API UAwakeAudioPlayer : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAwakeAudioPlayer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Actor to play sound on
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Audio")
	AActor* m_ActorTarget;
	//a sound to play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Audio")
	USoundBase* m_SoundToPlay;
};
