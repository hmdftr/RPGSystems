// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class RPGSYSTEMS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACharacterBase();

protected:
	
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo();

	UPROPERTY(EditAnywhere, Category="Custom Values|Character Info")
	FGameplayTag CharacterTag;



};