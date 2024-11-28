// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/RPGAbilitySystemComponent.h"

void URPGAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilitiesToGrant)
{
	for (const TSubclassOf<UGameplayAbility>& Ability: AbilitiesToGrant)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, 1.f);
		GiveAbility(AbilitySpec);
	}
}

void URPGAbilitySystemComponent::AddCharacterPassiveAbilities(
	const TArray<TSubclassOf<UGameplayAbility>>& PassivesToGrant)
{
	for (const TSubclassOf<UGameplayAbility>& Ability: PassivesToGrant)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, 1.f);
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
}

void URPGAbilitySystemComponent::InitializeDefaultAttributes(const TSubclassOf<UGameplayEffect>& AttributeEffect)
{
	checkf(AttributeEffect, TEXT("No Valid default attributes for this charter %s"), *GetAvatarActor()->GetName());
	
	const FGameplayEffectContextHandle ContextHandle = MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle= MakeOutgoingSpec(AttributeEffect, 1.f, ContextHandle);
	ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}
