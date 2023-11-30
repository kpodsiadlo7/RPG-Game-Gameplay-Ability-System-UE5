// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RPGPlayerState.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"

ARPGPlayerState::ARPGPlayerState()
{
	// Jak często serwer będzie aktualizował klientów
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ARPGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
