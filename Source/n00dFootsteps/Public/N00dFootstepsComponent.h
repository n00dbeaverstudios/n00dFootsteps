// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FN00dFootstepsTypes.h"
#include "Components/SkeletalMeshComponent.h"
#include "N00dFootstepsSettings.h"

#include "N00dFootstepsComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class N00DFOOTSTEPS_API UN00dFootstepsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UN00dFootstepsComponent();

protected:

	/////////////////////////////////////////////// PROPERTIES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	///////////////////////////////
	//	HIDDEN FROM DESIGNER
	///////////////////////////////

	// These values can only be written to or read from

	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		TEnumAsByte<EPhysicalSurface> CurrentSurfaceType;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		class UParticleSystem* CurrentCascadeEffect;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		class UNiagaraSystem* CurrentNiagaraEffect;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		FVector CurrentHitLocation;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		struct FN00dFootstepsEffectMap CurrentEffect;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		struct FGameplayTag CurrentFoley;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		bool ShouldFoley;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		struct FGameplayTag CurrentSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		struct FN00dFootstepsData CurrentData;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		struct FGameplayTag CurrentFootprint;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		FRotator CurrentRotation;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		class UAudioComponent* AudioComponent;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		TArray<int32> ActiveAudioComponents;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		class USkeletalMeshComponent* FootstepsMesh;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		class ACharacter* OwningCharacter;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		TArray<UMaterialInterface*> EffectMaterials;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		class UUserWidget* DebugWidget;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Footsteps")
		TArray<FN00dFootstepsEffectMap> LoadedEffects;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	/////////////////////////////////////////////// FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	///////////////////////////////
	//	DEBUG
	///////////////////////////////


	// Is the component disabled
	UFUNCTION(BlueprintCallable, Category = "N00d|Footsteps|Debug")
		bool IsFootstepsComponentDisabled();


	///////////////////////////////
	//	FUNCTIONALITY
	///////////////////////////////

	 
	// MEAT 'N GRAVY

	// Called on AnimNotify to initialise the footstep logic per execute
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		bool Footstep(FN00dFootstepsData Data, class USkeletalMeshComponent* OwnerMesh);
// Build references to the owner objects we care about
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		bool BuildReferences();

	// UTILITY

	// Show the debug widget if we're debugging
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		bool ShowFootstepsDebugWidget();
	// Trace from the defined socket, between the specified points 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		bool FootstepTrace();
	// Find the points for start and end of the trace by tracing between the differential from the defined socket 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00d|Footsteps|System")
		void GetFootTracePoint(const FName ForSocket, const float Differential, FVector &TracePoint);
	// Do the actual thing after passing the conditions
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		bool FootstepNotify();
	// Load the plugin's settings
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		void LoadFootstepsSettings();

	// EFFECTS

	// Play the effect 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool FootstepEffect();
	// Override for handling Cascade effects
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool CascadeFootstep();
	// Override for handling Niagara effects 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool NiagaraFootstep();
	// Apply the footprint decal 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool FootstepDecal();
	// Play the defined sound for the current surface 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool FootstepSound();
	// Override for handling the sound check 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool AddFootstepToActiveSound();
	// Override for Applying any specific sound parameters for our defined CUE 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool ApplyFootstepSoundParameters(class UAudioComponent* AComponent);
	// Event that fires when the spawned sound has finished playing 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		void FootstepAudioFinished();
	// Handle the actual AudioFinished event that isn't allowed properties 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool RemoveFootstepFromActiveSound();
	// Play a random sound from the array for the current surface 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00d|Footsteps|Effects")
		void GetRandomFootstepFoleyWave(class USoundWave* &Wave, float &Volume);
	// Play a random sound from the array for the current surface 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00d|Footsteps|Effects")
		void GetRandomFootstepSurfaceWave(class USoundWave* &Wave);
	// Set decal rotation
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|Effects")
		bool SetFootstepDecalRotation();
	// Get the effect for the defined surface
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00d|Footsteps|Effects")
		void GetCurrentFootstepEffect(EPhysicalSurface ForSurface, FN00dFootstepsEffectMap &Effect);

	// SETTERS

	// Assign the foley type 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		void SetFootstepFoley(const struct FGameplayTag FoleyType);
	// Should foley 
	UFUNCTION(BlueprintCallable, Category = "N00d|Footsteps|System")
		void SetShouldFootstepFoley(const bool DoTheFoley);
	// Set the footprint decals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		void SetFootprint(struct FGameplayTag FootprintType);
	// Set the desired speed
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		void SetFootstepsSpeed(struct FGameplayTag Speed);
	// Override for handling check on the mesh 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00d|Footsteps|System")
		bool FootstepsMeshCheck(class USkeletalMeshComponent* ActiveMesh);
	// Get the footsteps settings
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "N00d|Footsteps|System")
		void GetFootstepsSettings(UN00dFootstepsSettings*& FootstepsSettings);


};
