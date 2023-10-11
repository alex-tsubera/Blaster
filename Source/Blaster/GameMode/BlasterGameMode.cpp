// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterGameMode.h"
#include "GameFramework/PlayerState.h"
#include "Components/WidgetComponent.h"
#include "../Character/BlasterCharacter.h"
#include "../HUD/OverheadWidget.h"

void ABlasterGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, FString::Printf(TEXT("NewPlayer: %s"), *NewPlayer->PlayerState->GetPlayerName()));
	}

	if (ABlasterCharacter* Character = Cast<ABlasterCharacter>(NewPlayer->GetCharacter()))
	{
		if (UOverheadWidget* Widget = Cast<UOverheadWidget>(Character->GetOverheadWidget()->GetUserWidgetObject()))
		{
			Widget->ShowPlayerName(Character);
		}
	}
}
