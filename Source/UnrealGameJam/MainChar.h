#pragma once

#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "MainChar.generated.h"

class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS(Abstract)
class UNREALGAMEJAM_API AMainChar : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> _Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool BoolHitModifier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=TexCreate_InputAttachmentRead,
		meta =(AllowPrivateAccess = "true"))
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=TexCreate_InputAttachmentRead,
		meta =(AllowPrivateAccess = "true"))
	UInputAction* MidHit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=TexCreate_InputAttachmentRead,
		meta =(AllowPrivateAccess = "true"))
	UInputAction* LeftHit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=TexCreate_InputAttachmentRead,
		meta =(AllowPrivateAccess = "true"))
	UInputAction* RightHit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=TexCreate_InputAttachmentRead,
		meta =(AllowPrivateAccess = "true"))
	UInputAction* HitModifier;

public:
	// Sets default values for this character's properties
	AMainChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MidNote(const FInputActionValue& Value);
	void LeftNote(const FInputActionValue& Value);
	void RightNote(const FInputActionValue& Value);
	void HitNoteModifier(const FInputActionValue& Value);
	void EndHitNoteModifier(const FInputActionValue& Value);
	void HoldNote(const FInputActionValue& Value);

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void HitQ();

	UFUNCTION(BlueprintImplementableEvent)
	void HitW();

	UFUNCTION(BlueprintImplementableEvent)
	void HitE();
};
