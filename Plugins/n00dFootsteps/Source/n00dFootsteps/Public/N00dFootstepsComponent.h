/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FN00dFootstepsTypes.h"
#include "Components/SkeletalMeshComponent.h"

#include "N00dFootstepsComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class N00DFOOTSTEPS_API UN00dFootstepsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UN00dFootstepsComponent();


	/////////////////////////////////////////////// PROPERTIES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	///////////////////////////////
	//	DEBUG
	///////////////////////////////

	// Enabling this will print and activate any various debugging info relevant to n00dFootsteps
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dFootsteps|Debug")
		bool DebugFootstepsComponent;
	// Don't use this component for any reason in particular 
	UPROPERTY(EditAnywhere, Category = "N00dFootsteps|Debug")
		bool DisableFootstepsComponent;
	// Only works if the component is in debug mode 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "N00dFootsteps|Debug")
		bool PrintActiveFootstepSounds;
	// Let us know if there are any decals missing for the current surface 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "N00dFootsteps|Debug")
		bool PrintNullFootstepDecals;

	///////////////////////////////
	//	CONFIG
	///////////////////////////////

	// Surfaces and their relevant effects 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dFootsteps|Config")
		TMap<TEnumAsByte<EPhysicalSurface>, struct FN00dFootstepsEffectMap> FootstepSurfaces;
	// For each tag we define (i.e. Armour), allocate foley for that definition 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dFootsteps|Config")
		TMap<struct FGameplayTag, struct FN00dFootstepsWavesVolume> FootstepFoley;
	// User defined speeds and their values 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dFootsteps|Config")
		TMap<struct FGameplayTag, float> GlobalFootstepsVolume;


	///////////////////////////////
	//	HIDDEN FROM DESIGNER
	///////////////////////////////

	// These values can only be written to or read from

	UPROPERTY(BlueprintReadWrite, Category = default)
		TEnumAsByte<EPhysicalSurface> CurrentSurfaceType;
	UPROPERTY(BlueprintReadWrite, Category = default)
		class UParticleSystem* CurrentCascadeEffect;
	UPROPERTY(BlueprintReadWrite, Category = default)
		class UNiagaraSystem* CurrentNiagaraEffect;
	UPROPERTY(BlueprintReadWrite, Category = default)
		FVector CurrentHitLocation;
	UPROPERTY(BlueprintReadWrite, Category = default)
		struct FN00dFootstepsEffectMap CurrentEffect;
	UPROPERTY(BlueprintReadWrite, Category = default)
		struct FGameplayTag CurrentFoley;
	UPROPERTY(BlueprintReadWrite, Category = default)
		bool ShouldFoley;
	UPROPERTY(BlueprintReadWrite, Category = default)
		struct FGameplayTag CurrentSpeed;
	UPROPERTY(BlueprintReadWrite, Category = default)
		struct FN00dFootstepsData CurrentData;
	UPROPERTY(BlueprintReadWrite, Category = default)
		struct FGameplayTag CurrentFootprint;
	UPROPERTY(BlueprintReadWrite, Category = default)
		FRotator CurrentRotation;
	UPROPERTY(BlueprintReadWrite, Category = default)
		class UAudioComponent* AudioComponent;
	UPROPERTY(BlueprintReadWrite, Category = default)
		TArray<int32> ActiveAudioComponents;
	UPROPERTY(BlueprintReadWrite, Category = default)
		class USkeletalMeshComponent* FootstepsMesh;
	UPROPERTY(BlueprintReadWrite, Category = default)
		class ACharacter* OwningCharacter;
	UPROPERTY(BlueprintReadWrite, Category = default)
		TArray<UMaterialInterface*> EffectMaterials;
	UPROPERTY(BlueprintReadWrite, Category = default)
		class UUserWidget* DebugWidget;
 
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


	// Debug
	UFUNCTION(BlueprintCallable, Category = "N00dAssets|Footsteps|Debug")
		void FootstepsDebug(const FString InString, const FDebugOptions Options, class UUserWidget* &DebugWidgetOut, FString &OutString, FDebugOptions &OutOptions);
	// Create the debug widget
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Debug")
		bool CreateFootstepsDebugWidget(class APlayerController* OwningPlayer);
	// Is the component disabled
	UFUNCTION(BlueprintCallable, Category = "N00dAssets|Footsteps|Debug")
		bool IsFootstepsComponentDisabled();



	///////////////////////////////
	//	FUNCTIONALITY
	///////////////////////////////

	 
	// Meat and Gravy

	// Called on AnimNotify to initialise the footstep logic per execute
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		bool Footstep(FN00dFootstepsData Data, class USkeletalMeshComponent* OwnerMesh);

	// Utility

	// Trace from the defined socket, between the specified points 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		bool FootstepTrace(FName OnSocket);
	// Find the points for start and end of the trace by tracing between the differential from the defined socket 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dAssets|Footsteps|System")
		void GetFootTracePoint(const FName ForSocket, const float Differential, FVector &TracePoint);
	// Do the actual thing after passing the conditions
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		bool FootstepNotify();
	// Calling this is not mandatory and is used to reference the character for debug purposes.  
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		bool ConstructFootstepsCharacter(class ACharacter* Character);

	// Effects

	// Play the effect 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool FootstepEffect();
	// Apply a material to the effect
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool FootstepEffectMaterial(UPrimitiveComponent* SystemComponent);
	// Override for handling Cascade effects
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool CascadeFootstep();
	// Override for handling Niagara effects 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool NiagaraFootstep();
	// Apply the footprint decal 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool FootstepDecal();
	// Play the defined sound for the current surface 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool FootstepSound();
	// Override for handling the sound check 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool AddFootstepToActiveSound(int32 Add);
	// Override for Applying any specific sound parameters for our defined CUE 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool ApplyFootstepSoundParameters(class UAudioComponent* AComponent);
	// Event that fires when the spawned sound has finished playing 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		void FootstepAudioFinished();
	// Handle the actual AudioFinished event that isn't allowed properties 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|Effects")
		bool RemoveFootstepFromActiveSound();
	// Get the decal and its relevant settings 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dAssets|Footsteps|Effects")
		void GetFootprint(UMaterialInterface* &FootprintMaterial, FN00dFootstepsDecalSettings &FootprintDetails);
	// Play a random sound from the array for the current surface 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dAssets|Footsteps|Effects")
		void GetRandomFootstepFoleyWave(class USoundWave* &Wave, float &Volume);
	// Play a random sound from the array for the current surface 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dAssets|Footsteps|Effects")
		void GetRandomFootstepSurfaceWave(class USoundWave* &Wave);

	// Checks

	// Override for handling check on the mesh 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure, Category = "N00dAssets|Footsteps|Checks")
		bool FootstepsMeshCheck(class USkeletalMeshComponent* ActiveMesh);

	// Setters

	// Assign the foley type 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		void SetFootstepFoley(const struct FGameplayTag FoleyType);
	// Should foley 
	UFUNCTION(BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		void SetShouldFootstepFoley(const bool DoTheFoley);
	// Set the footprint decals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		void SetFootprint(struct FGameplayTag FootprintType);
	// Set the desired speed
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		void SetFootstepsSpeed(struct FGameplayTag Speed);
	// Set decal rotation
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		bool SetFootstepDecalRotation();
	// Reference the mesh to use
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dAssets|Footsteps|System")
		bool ConstructFootstepsMesh(class USkeletalMeshComponent* Mesh);




};
