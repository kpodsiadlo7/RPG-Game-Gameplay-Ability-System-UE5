// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "Interaction/HighlightInterface.h"
#include "MainEnemy.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNRPG_API AAuraEnemy : public ARPGCharacterBase, public IHighlightInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	//IHighlightInterface
	virtual void HighlightActor() override;
	void TurnOnAndOffCustomDepth(bool Highlight);
	//IHighlightInterface
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
