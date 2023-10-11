// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(const FString& Text)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(Text));
	}
}

FString NetRoleToString(ENetRole Role)
{
	switch (Role)
	{
	case ENetRole::ROLE_Authority:
		return FString("Authority");
	case ENetRole::ROLE_AutonomousProxy:
		return FString("Authonomous Proxy");
	case ENetRole::ROLE_SimulatedProxy:
		return FString("Simulated Proxy");
	default:
		return FString("None");
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	ENetRole RemoteRole = InPawn->GetRemoteRole();

	SetDisplayText(FString::Printf(TEXT("Local Role: %s\nRemote Role: %s"), *NetRoleToString(LocalRole), *NetRoleToString(RemoteRole)));
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	if (APlayerState* PS = InPawn->GetPlayerState())
	{
		SetDisplayText(PS->GetPlayerName());
	}
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();

	Super::NativeDestruct();
}
