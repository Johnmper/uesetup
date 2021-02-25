// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"
#include "GridBase.h"

// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mGridToSpawn = AGridBase::StaticClass();
	mGridList = TArray<AGridBase*>();


}

// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();

	// Spawn the grid!!
	const size_t gridSizeX = 10;
	const size_t gridSizeY = 8;
	for (size_t gridX = 0; gridX < gridSizeX; gridX++)
	{
		for (size_t gridY = 0; gridY < gridSizeY; gridY++)
		{
			UWorld* world = GetWorld();
			FRotator rotation(0);
			FVector position(float(100*gridX), float(100*gridY), 0.0f);
			AGridBase* gridElem = Cast<AGridBase>(world->SpawnActor(mGridToSpawn, &position, &rotation));
			mGridList.Add(gridElem);
			UE_LOG(LogTemp, Warning, TEXT("Spawned One Grid"));
		}
	}
	
}

// Called every frame
void AMapGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector2D AMapGenerator::getRandomLocation2D(FVector2D limits)
{
	const float randX = FMath::FRandRange(-1.0f, 1.0f) * limits.X;
	const float randY = FMath::FRandRange(-1.0f, 1.0f) * limits.Y;
	return FVector2D(randX, randY);
}