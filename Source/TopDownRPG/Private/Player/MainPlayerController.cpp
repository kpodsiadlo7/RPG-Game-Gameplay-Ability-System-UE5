// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MainPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Enemy/MainEnemy.h"
#include "Interaction/HighlightInterface.h"

AMainPlayerController::AMainPlayerController()
{
	bReplicates = true;
}

void AMainPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MainContex);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MainContex, 0);
		// Ustawienia dla myszki
		bShowMouseCursor = true;
		DefaultMouseCursor = EMouseCursor::Default;
		FInputModeGameAndUI InputModeData;
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		InputModeData.SetHideCursorDuringCapture(false);
		SetInputMode(InputModeData);
	}
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayerController::Move);
}

void AMainPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Kierunek w przód/tył
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		// Kierunek w lewo/prawo
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AMainPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit && !CursorHit.GetActor()) return;

	// Jeżeli pobrany aktor nie jest klasy AAuraEnemy to wyłączamy podświetlenie na potworkach
	if (!CursorHit.GetActor()->IsA<AAuraEnemy>())
	{
		if (LastActor != nullptr)
		{
			LastActor->UnHighlightActor();
			LastActor = nullptr;
		}
		if (ThisActor != nullptr)
		{	
			ThisActor->UnHighlightActor();
			ThisActor = nullptr;
		}
		return;
	}
	LastActor = ThisActor;
	ThisActor = Cast<IHighlightInterface>(CursorHit.GetActor());

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Scenariusz B
			ThisActor->HighlightActor();
		}
	}
		/*else
		{
			// Scenariusz A - nie rób nic
		}
	}*/
	/*else // 'LastActor' != nullptr
	{
		if (ThisActor == nullptr)
		{
			// Scenariusz C
			LastActor->UnHighlightActor();
		}
		else // 'LastActor' != nullptr i 'ThisActor' != nullptr
		{
			if (LastActor != ThisActor)
			{
				// Scenariusz D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Scenariusz E - nie rób nic
			}
		}
	}*/
}
