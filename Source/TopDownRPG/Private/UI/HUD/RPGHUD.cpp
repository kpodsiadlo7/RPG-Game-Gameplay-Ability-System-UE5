// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/RPGHUD.h"

#include "Blueprint/UserWidget.h"

void ARPGHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
