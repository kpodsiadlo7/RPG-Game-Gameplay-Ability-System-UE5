// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"


class UInputMappingContex;
/**
 * 
 */
UCLASS()
class TOPDOWNRPG_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMainPlayerController();

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category=Input)
	TObjectPtr<UInputMappingContext> MainContex;
};
