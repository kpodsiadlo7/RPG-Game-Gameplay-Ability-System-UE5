// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\Public\Enemy\MainEnemy.h"

#include "TopDownRPG/TopDownRPG.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	GetMesh()->SetRenderCustomDepth(false);
	
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(false);

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	TurnOnAndOffCustomDepth(bHighlighted = true);
}

void AAuraEnemy::UnHighlightActor()
{
	TurnOnAndOffCustomDepth(bHighlighted = false);
}

void AAuraEnemy::TurnOnAndOffCustomDepth(bool Highlight)
{
	GetMesh()->SetRenderCustomDepth(Highlight);
	Weapon->SetRenderCustomDepth(Highlight);
}
