// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"


void AEnemy_Turret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the Tank
    if (Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        // Check to see if the Tank is in range
        if (Distance <= FireRange)
        {
            // If in range, rotate turret toward Tank
            RotateTurret(Tank->GetActorLocation());
        }
    }
}

void AEnemy_Turret::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
