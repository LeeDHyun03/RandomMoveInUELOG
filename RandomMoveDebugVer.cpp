// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMoveDebugVer.h"

// Sets default values
ARandomMoveDebugVer::ARandomMoveDebugVer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomMoveDebugVer::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(eventHandle, this, &ARandomMoveDebugVer::move, 1.0f, true, 0.0f);
}

// Called every frame
void ARandomMoveDebugVer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

