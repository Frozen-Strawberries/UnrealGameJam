#include "MainChar.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

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
}

void AMainChar::MidNote(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Button pressed"));
}
void AMainChar::LeftNote(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Button pressed"));
}

void AMainChar::RightNote(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Button pressed"));
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
		
	}
}



