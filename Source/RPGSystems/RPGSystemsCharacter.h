// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "RPGSystemsCharacter.generated.h"

class URPGAttributeSet;
class URPGAbilitySystemComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ARPGSystemsCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	ARPGSystemsCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
			
//protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void NotifyControllerChanged() override;
	virtual void BeginPlay();

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URPGAbilitySystemComponent> RPGAbilitySystemComp;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URPGAttributeSet> RPGAttributes;

	UPROPERTY(EditAnywhere, Category="Custom Values|Character Info")
	FGameplayTag CharacterTag;
	
	void InitAbilityActorInfo();
	void InitClassDefaults();
	
public:

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

