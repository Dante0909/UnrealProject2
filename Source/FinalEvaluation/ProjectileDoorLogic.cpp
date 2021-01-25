// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileDoorLogic.h"
#include "Engine/Engine.h"
#include "ComponentHelper.h"
// Sets default values for this component's properties
UProjectileDoorLogic::UProjectileDoorLogic()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	
}


// Called when the game starts
void UProjectileDoorLogic::BeginPlay()
{
	Super::BeginPlay();
	door = Cast<USceneComponent>(ComponentHelper::GetComponentByName(GetOwner(), "Door"));
	
	
	EndzPosition = door->GetComponentLocation().Z + 301.5f;
	//GEngine->AddOnScreenDebugMessage(0, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), EndzPosition));
	// ...
	
}


// Called every frame
void UProjectileDoorLogic::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UProjectileDoorLogic::HandleShot() {
	
	
	if (door->GetComponentLocation().Z < EndzPosition) {
		door->AddLocalOffset(FVector(0, 0, 201/5.0f));
	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), door->GetComponentLocation().Z));
}

