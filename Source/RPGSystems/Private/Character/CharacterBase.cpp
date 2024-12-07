// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::InitAbilityActorInfo()
{
	//leave it for now
}

void ACharacterBase::BindCallbacksToDependencies()
{
	//leave it for now
}

void ACharacterBase::InitClassDefaults()
{
	//leave it for now
}

void ACharacterBase::BroadcastInitialValues()
{
	//leave it for now
}

