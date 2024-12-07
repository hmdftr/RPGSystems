// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Attributes/RPGAttributeSet.h"
#include "Character/CharacterBase.h"
#include "EnemyBase.generated.h"

class URPGAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class RPGSYSTEMS_API AEnemyBase : public ACharacterBase, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AEnemyBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:

	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

private:

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<URPGAbilitySystemComponent> RPGAbilitySystemComp;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<URPGAttributeSet> RPGAttributes;

	void InitClassDefaults();
};

