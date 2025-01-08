// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomMoveDebugVer.generated.h"

UCLASS()
class PROJECT_1_API ARandomMoveDebugVer : public AActor
{
	GENERATED_BODY()
private:
	FVector2D currentVector = FVector2D(0, 0);
	FVector2D moveVector = FVector2D(0, 0);
	FTimerHandle eventHandle;
	int32 stepCount = 0;
	int32 eventCount = 0;
	float myDistance = float();
public:	
	// Sets default values for this actor's properties
	ARandomMoveDebugVer();
	void move()
	{
		step();
		randomEvent();
		if (stepCount == 10)
		{
			GetWorld()->GetTimerManager().ClearTimer(eventHandle);
			myDistance = Distance(FVector2D(0, 0), currentVector);
			UE_LOG(LogTemp, Log, TEXT("Total Event Count: %d"), eventCount);
			UE_LOG(LogTemp, Log, TEXT("Total Move Distance: %f"), myDistance);
		}
	}
	void step()
	{
		stepCount++;
		UE_LOG(LogTemp, Log, TEXT("------------------------------step %d"), stepCount);
		moveVector.X = FMath::RandRange(0, 1);
		moveVector.Y = FMath::RandRange(0, 1);
		if (moveVector.X == 0 && moveVector.Y == 0) moveVector.X = 1;
		myDistance = Distance(currentVector, currentVector + moveVector);
		currentVector += moveVector;
		UE_LOG(LogTemp, Log, TEXT("currentPos: %s"), *currentVector.ToString());
		UE_LOG(LogTemp, Log, TEXT("currentDistance: %f"), myDistance);
	}
	void randomEvent()
	{
		int32 randomIndex = FMath::RandRange(0, 1);
		if (randomIndex == 1)
		{
			UE_LOG(LogTemp, Warning, TEXT("Event!!"));
			eventCount++;
		}
	}
	float Distance(FVector2D startVector, FVector2D endVector)
	{
		//FVector::Distance(startVector, endVector)
		float distance = FMath::Sqrt(FMath::Square(startVector.X - endVector.X) + FMath::Square(startVector.Y - endVector.Y));
		return distance;
	}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
