// Fill out your copyright notice in the Description page of Project Settings.


#include "GridBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AGridBase::AGridBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	grid_component = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	if (grid_component)
	{
		SetRootComponent(grid_component);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> grid_mesh(TEXT("/Game/Meshes/Basic/Plane"));
		if (grid_mesh.Succeeded())
		{
			grid_component->SetStaticMesh(grid_mesh.Object);
			grid_component->SetRelativeLocation(FVector(0, 0, 0));
			// Leave a gap so it is easy to visualize each square
			grid_component->SetWorldScale3D(FVector(0.98, 0.98, 1.0f));
		}
	}
}

// Called when the game starts or when spawned
void AGridBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

