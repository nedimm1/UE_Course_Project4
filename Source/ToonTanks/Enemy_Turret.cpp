// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "TimerManager.h"



void AEnemy_Turret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the Tank
    if (InFireRange())
    {
       RotateTurret(Tank->GetActorLocation());
    }
}

void AEnemy_Turret::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemy_Turret::CheckFireCondition, FireRate, true);

}

void AEnemy_Turret::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}



void AEnemy_Turret::CheckFireCondition()
{
    if (InFireRange())
    {
        Fire();
    }
}

bool AEnemy_Turret::InFireRange()
{
    if (Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        if (Distance <= FireRange)
        {
            return true;
        }
    }

    return false;
}
