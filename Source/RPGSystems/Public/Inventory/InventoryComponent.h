// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

USTRUCT()
struct FPackagedInventory
{
	GENERATED_BODY()

	virtual ~FPackagedInventory() = default;
	
	UPROPERTY()
	TArray<FGameplayTag> ItemTags;

	UPROPERTY()
	TArray<int32> ItemQuantities;

	virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess);
};
template<>
struct TStructOpsTypeTraits<FPackagedInventory> : TStructOpsTypeTraitsBase2<FPackagedInventory>
{
	enum
	{
		WithNetSerializer = true
	};
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGSYSTEMS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION(BlueprintCallable)
	void AddItem(const FGameplayTag& ItemTag, int32 NumItems = 1);


private:

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess=true))
	TMap<FGameplayTag, int32> InventoryTagMap;

	UPROPERTY(ReplicatedUsing=OnRep_CachedInventory)
	FPackagedInventory CachedInventory;

	UFUNCTION(Server, Reliable)
	void ServerAddItem(const FGameplayTag& ItemTag, int32 NumItems);

	void PackageInventory(FPackagedInventory& OutInventory);
	void ReconstructInventoryMap(const FPackagedInventory& Inventory);
	
	UFUNCTION()
	void OnRep_CachedInventory();
};
