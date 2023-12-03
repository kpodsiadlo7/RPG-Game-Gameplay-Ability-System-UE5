// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/RPGWidgetController.h"

void URPGWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	PlayerController = WCParams.PlayerController;
	AttributeSet = WCParams.AttributeSet;
	PlayerState = WCParams.PlayerState;
}
