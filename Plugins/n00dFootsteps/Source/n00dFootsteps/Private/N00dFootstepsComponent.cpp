/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */


#include "N00dFootstepsComponent.h"

// Sets default values for this component's properties
UN00dFootstepsComponent::UN00dFootstepsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;


	// ...
}


// Called when the game starts
void UN00dFootstepsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UN00dFootstepsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



// MASTER

	/* Debug */
void UN00dFootstepsComponent::FootstepsDebug(const FString InString, const FDebugOptions Options, class UUserWidget* &DebugWidgetOut, FString &OutString, FDebugOptions &OutOptions)
{
	// ...
}

	/* Create Debug Widget */
bool UN00dFootstepsComponent::CreateFootstepsDebugWidget_Implementation(class APlayerController* OwningPlayer)
{
	return false;
}

	/* Component Disabled */
bool UN00dFootstepsComponent::IsFootstepsComponentDisabled()
{
	if (DisableFootstepsComponent) /* Check to see if the component has been flagged as disabled */
	{
		bool LocalDisabled;
		LocalDisabled = true;

			if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, TEXT("FOOTSTEPS ARE DISABLED!"));

		return true;
	}

	return false;
}


// n00dFootsteps


// Meat 'n Gravy

	/* Footstep */
bool UN00dFootstepsComponent::Footstep_Implementation(FN00dFootstepsData Data, class USkeletalMeshComponent* OwnerMesh)
{
	return false;
}

// UTILITY

	/* Trace */
bool UN00dFootstepsComponent::FootstepTrace_Implementation(FName OnSocket)
{
	return false;
}

	/* Get Trace Point */
void UN00dFootstepsComponent::GetFootTracePoint_Implementation(const FName ForSocket, const float Differential, FVector &TracePoint)
{
	if (FootstepsMesh)
	{
		UN00dFootstepsComponent::FootstepsMesh->GetSocketLocation(ForSocket);

		return;
	}
}

	/* Notify */
bool UN00dFootstepsComponent::FootstepNotify_Implementation()
{
	return false;
}

/* Set Owning Character */
bool UN00dFootstepsComponent::ConstructFootstepsCharacter_Implementation(class ACharacter* OwningPawn)
{
	return false;
}


// EFFECTS

	/* Particle Effect */
bool UN00dFootstepsComponent::FootstepEffect_Implementation()
{
	return false;
}

bool UN00dFootstepsComponent::FootstepEffectMaterial_Implementation(UPrimitiveComponent * SystemComponent)
{
	return false;
}

	/* Cascade */
bool UN00dFootstepsComponent::CascadeFootstep_Implementation()
{
	return false;
}

	/* Niagara */
bool UN00dFootstepsComponent::NiagaraFootstep_Implementation()
{
	return false;
}

	/* Decal */
bool UN00dFootstepsComponent::FootstepDecal_Implementation()
{
	return false;
}

	/* Sound */
bool UN00dFootstepsComponent::FootstepSound_Implementation()
{
	return false;
}

/* Sound Check */
bool UN00dFootstepsComponent::AddFootstepToActiveSound_Implementation(const int32 New)
{
	return false;
}

	/* Apply Sound Parameters */
bool UN00dFootstepsComponent::ApplyFootstepSoundParameters_Implementation(class UAudioComponent* ApplyToComponent)
{
	return false;
}

	/* Audio Finished */
void UN00dFootstepsComponent::FootstepAudioFinished_Implementation()
{
	// ...
}

/* Handle Audio Finished */
bool UN00dFootstepsComponent::RemoveFootstepFromActiveSound_Implementation()
{
	return false;
}

	/* Get Footprint */
void UN00dFootstepsComponent::GetFootprint_Implementation(UMaterialInterface* &Footprint, FN00dFootstepsDecalSettings &Details)
{

}

/* Get Random Foley Wave */
void UN00dFootstepsComponent::GetRandomFootstepFoleyWave_Implementation(class USoundWave* &WaveToUse, float &AtVolume)
{

}

/* Get Random Surface Wave */
void UN00dFootstepsComponent::GetRandomFootstepSurfaceWave_Implementation(class USoundWave* &WaveToUse)
{

}



// CHECKS




	/* Mesh Check */
bool UN00dFootstepsComponent::FootstepsMeshCheck_Implementation(class USkeletalMeshComponent* ActiveMesh)
{
	return false;
}


// Setters


	/* Set Foley */
void UN00dFootstepsComponent::SetFootstepFoley_Implementation(const struct FGameplayTag FoleyType)
{

}

	/* Set Should Foley */
void UN00dFootstepsComponent::SetShouldFootstepFoley(const bool DoTheFoley)
{
	if (DoTheFoley)
	{
		ShouldFoley = true;
	}
	else
	{
		ShouldFoley = false;
		return;
	}
}

	/* Set Footprint */
void UN00dFootstepsComponent::SetFootprint_Implementation(struct FGameplayTag FootprintType)
{
	//... 
}

	/* Set Speed */
void UN00dFootstepsComponent::SetFootstepsSpeed_Implementation(struct FGameplayTag Speed)
{
	//...
}

	/* Set Decal Rotation */
bool UN00dFootstepsComponent::SetFootstepDecalRotation_Implementation()
{
	return false;
}

	/* Set Footsteps Mesh Component */
bool UN00dFootstepsComponent::ConstructFootstepsMesh_Implementation(class USkeletalMeshComponent* Mesh)
{
	return false;
}


