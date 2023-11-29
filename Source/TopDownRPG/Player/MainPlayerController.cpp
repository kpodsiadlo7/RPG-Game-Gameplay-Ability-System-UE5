// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainPlayerController.h"
#include "EnhancedInputSubsystems.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MainContex);

	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MainContex, 0);
		// Ustawienia dla myszki
		bShowMouseCursor = true;
		DefaultMouseCursor = EMouseCursor::Default;
		FInputModeGameAndUI InputmodeData;
		InputmodeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		InputmodeData.SetHideCursorDuringCapture(false);
		SetInputMode(InputmodeData);
	}
}
