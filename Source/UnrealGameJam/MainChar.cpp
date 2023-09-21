#include "MainChar.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MusicNoteCollector.h"

AMainChar::AMainChar()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.f);

	_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_Camera->SetupAttachment(GetCapsuleComponent());
	_Camera->SetRelativeLocation(FVector(-380.f, 0.f, 150.f));
}

void AMainChar::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void AMainChar::LeftNote(const FInputActionValue& Value)
{
	if (BoolHitModifier)
	{
		HitQShift();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift + Q pressed"));
	}
	else
	{
		GetMesh()->SetRelativeLocation(FVector(0.f, -200.f, -100.f));
		HitQ();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Q pressed"));
	}
}

void AMainChar::MidNote(const FInputActionValue& Value)
{
	if (BoolHitModifier)
	{
		HitWShift();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift + W pressed"));
	}
	else
	{
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -100.f));
		HitW();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("W pressed"));
	}
}

void AMainChar::RightNote(const FInputActionValue& Value)
{
	if (BoolHitModifier)
	{
		HitEShift();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift + E pressed"));
	}
	else
	{
		GetMesh()->SetRelativeLocation(FVector(0.f, 200.f, -100.f));
		HitE();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("E pressed"));
	}
}

void AMainChar::HitNoteModifier(const FInputActionValue& Value)
{
	BoolHitModifier = true;
}

void AMainChar::EndHitNoteModifier(const FInputActionValue& Value)
{
	BoolHitModifier = false;
}

void AMainChar::HoldNote(const FInputActionValue& Value)
{
}

void AMainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MidHit, ETriggerEvent::Triggered, this, &AMainChar::MidNote);
		// ONGOING EVENT FOR HOLDNOTE

		EnhancedInputComponent->BindAction(LeftHit, ETriggerEvent::Triggered, this, &AMainChar::LeftNote);
		// ONGOING EVENT FOR HOLDNOTE

		EnhancedInputComponent->BindAction(RightHit, ETriggerEvent::Triggered, this, &AMainChar::RightNote);
		// ONGOING EVENT FOR HOLDNOTE

		EnhancedInputComponent->BindAction(HitModifier, ETriggerEvent::Ongoing, this, &AMainChar::HitNoteModifier);
		EnhancedInputComponent->BindAction(HitModifier, ETriggerEvent::None, this, &AMainChar::EndHitNoteModifier);
	}
}
