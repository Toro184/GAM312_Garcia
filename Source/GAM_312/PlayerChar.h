// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingPart.h"
#include "PlayerWidget.h"
#include "ObjectiveWidget.h"
#include "PlayerChar.generated.h"



UCLASS()
class GAM_312_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// -------------------------------------------------------------------------------------------------------------------------------
	// Movements

	UFUNCTION()
		void MoveForward(float axisValue);

	UFUNCTION()
		void MoveRight(float axisValue);

	UFUNCTION()
		void StartJump();

	UFUNCTION()
		void StopJump();

	UFUNCTION()
		void ToggleCrouch();

	UFUNCTION()
		void FindObject();


	UPROPERTY(VisibleAnywhere)
		UCameraComponent* PlayerCamComp;

	// Health, Stamina and Hunger set at 100

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Stamina = 100.0f;

	// Resources

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Iron;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<FString> ResourcesNameArray;

	UPROPERTY(EditAnywhere, Category = "HitMaker")
		UMaterialInterface* hitDecal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")
		TArray<int32> BuildingArray;

	UPROPERTY()
		bool isBuilding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<ABuildingPart> BuildPartClass;

	UPROPERTY()
		ABuildingPart* spawnedPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPlayerWidget* playerUI;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<UPlayerWidget> PlayerWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObjectiveWidget* objWidget;

	UPROPERTY()
		float objectsBuilt;

	UPROPERTY()
		float matsCollected;

	// Set health, hunger and Stamina
	UFUNCTION(BlueprintCallable)
		void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	UFUNCTION(BlueprintCallable)
		void DecreaseStats();
		
	// Give resources
	UFUNCTION()
		void GiveResource(float amount, FString resourceType);

	// Updates building materials, spawn buildings and rotate buildings
	UFUNCTION(BlueprintCallable)
		void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);

	UFUNCTION(BlueprintCallable)
		void SpawnBuilding(int buildingID, bool& isSuccess);

	UFUNCTION(BlueprintCallable)
		void RotateBuilding();
};
