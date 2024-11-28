// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PlayerController/RPGPlayerController.h"

#include "Inventory/InventoryComponent.h"
#include "Net/UnrealNetwork.h"

ARPGPlayerController::ARPGPlayerController()
{
	bReplicates = true;

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("InventoryComponent");
	InventoryComponent->SetIsReplicated(true);
}

void ARPGPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARPGPlayerController, InventoryComponent);
}
