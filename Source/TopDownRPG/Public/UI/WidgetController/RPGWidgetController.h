// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RPGWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class TOPDOWNRPG_API URPGWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Widget Controller")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="Widget Controller")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet;
};
