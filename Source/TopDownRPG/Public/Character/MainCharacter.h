// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNRPG_API AAuraCharacter : public ARPGCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	void InitAbilityActorInfo();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
};
