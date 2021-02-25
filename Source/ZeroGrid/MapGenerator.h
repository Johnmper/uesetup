// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

class AGridBase;

UCLASS()
class ZEROGRID_API AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapGenerator();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> mGridToSpawn;

	UPROPERTY(BlueprintReadOnly)
	TArray<AGridBase*> mGridList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	static FVector2D getRandomLocation2D(FVector2D limits);

};
