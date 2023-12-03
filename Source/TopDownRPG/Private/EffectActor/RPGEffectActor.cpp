// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor/RPGEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"
#include "Character/MainCharacter.h"
#include "Components/SphereComponent.h"

// Sets default values
ARPGEffectActor::ARPGEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ARPGEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                const FHitResult& HitResult)
{
	if (IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const URPGAttributeSet* AttributeSet = Cast<URPGAttributeSet>(
			AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(URPGAttributeSet::StaticClass()));
		check(AttributeSet);
		
		//TODO: Zmień to używając GameplayEffect. Na ten moment używamy const_cast
		URPGAttributeSet* MutableRPGAttributeSet = const_cast<URPGAttributeSet*>(AttributeSet);
		MutableRPGAttributeSet->SetHealth(AttributeSet->GetHealth() - 20.f);
		Destroy();
	}
}

void ARPGEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void ARPGEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARPGEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ARPGEffectActor::EndOverlap);
}
