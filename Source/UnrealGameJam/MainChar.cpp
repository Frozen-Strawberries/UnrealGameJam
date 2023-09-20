#include "MainChar.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"

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

void AMainChar::MidNote(const FInputActionValue& Value)
{
	if (BoolHitModifier)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift + W pressed"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("W pressed"));
	}
}
void AMainChar::LeftNote(const FInputActionValue& Value)
{
	if (BoolHitModifier)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift + Q pressed"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Q pressed"));
	}
}

void AMainChar::RightNote(const FInputActionValue& Value)
{
	if (BoolHitModifier)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift + E pressed"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("E pressed"));
	}
}

void AMainChar::HitNoteModifier(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("SHIFT pressed"));
	BoolHitModifier = true;

}

void AMainChar::EndHitNoteModifier(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("SHIFT released"));
	BoolHitModifier = false;
}

void AMainChar::HoldNote(const FInputActionValue& Value)
{
	
}

void AMainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
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



