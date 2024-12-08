// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ProjectileAbility.h"
#include  "Projectiles/ProjectileBase.h"
#include "Data/ProjectileInfo.h"
#include "Libraries/RPGAbilitySystemLibrary.h"

UProjectileAbility::UProjectileAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UProjectileAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	AvatarActorFromInfo = GetAvatarActorFromActorInfo();

	if (!ProjectileToSpawnTag.IsValid() || !IsValid(AvatarActorFromInfo)) return;

	if (UProjectileInfo* ProjectileInfo = URPGAbilitySystemLibrary::GetProjectileInfo(GetAvatarActorFromActorInfo()))
	{
		CurrentProjectileParams = *ProjectileInfo->ProjectileInfoMap.Find(ProjectileToSpawnTag);
	}
}

void UProjectileAbility::SpawnProjectile()
{
	if (!IsValid(CurrentProjectileParams.ProjectileClass)) return;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan,
		FString::Printf(TEXT("Spawning Projectile %s On Server"), *CurrentProjectileParams.ProjectileClass->GetName()));
}
