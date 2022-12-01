// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 


#include "N00dFootstepsComponent.h"

// Sets default values for this component's properties
UN00dFootstepsComponent::UN00dFootstepsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

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



// print footstep debug
void UN00dFootstepsComponent::PrintFootstepDebug_Implementation(const FString& InString, FLinearColor TextColour, float Duration, FGameplayTag DebugTag)
{
}

// is component disabled 
bool UN00dFootstepsComponent::IsFootstepsComponentDisabled()
{
	return false;
}


// MEAT 'N GRAVY

// footstep
bool UN00dFootstepsComponent::Footstep_Implementation(FN00dFootstepsData Data, class USkeletalMeshComponent* OwnerMesh)
{
	return false;
}

// UTILITY

// trace
bool UN00dFootstepsComponent::FootstepTrace_Implementation()
{
	return false;
}

// get trace point
void UN00dFootstepsComponent::GetFootTracePoint_Implementation(const FName ForSocket, const float Differential, FVector &TracePoint)
{
	if (FootstepsMesh)
	{
		UN00dFootstepsComponent::FootstepsMesh->GetSocketLocation(ForSocket);

		return;
	}
}

// notify
bool UN00dFootstepsComponent::FootstepNotify_Implementation()
{
	return false;
}

// construct footsteps character
bool UN00dFootstepsComponent::ConstructFootstepsCharacter_Implementation(class ACharacter* OwningPawn)
{
	return false;
}

// load footsteps settings
void UN00dFootstepsComponent::LoadFootstepsSettings_Implementation()
{
}

// EFFECTS

// particle effect
bool UN00dFootstepsComponent::FootstepEffect_Implementation()
{
	return false;
}

// effect material
bool UN00dFootstepsComponent::FootstepEffectMaterial_Implementation(UPrimitiveComponent * SystemComponent)
{
	return false;
}

// cascade 
bool UN00dFootstepsComponent::CascadeFootstep_Implementation()
{
	return false;
}

// niagara
bool UN00dFootstepsComponent::NiagaraFootstep_Implementation()
{
	return false;
}

// decal 
bool UN00dFootstepsComponent::FootstepDecal_Implementation()
{
	return false;
}

// sound
bool UN00dFootstepsComponent::FootstepSound_Implementation()
{
	return false;
}

// sound check 
bool UN00dFootstepsComponent::AddFootstepToActiveSound_Implementation(const int32 New)
{
	return false;
}

// apply sound paramaters
bool UN00dFootstepsComponent::ApplyFootstepSoundParameters_Implementation(class UAudioComponent* ApplyToComponent)
{
	return false;
}

// audio finished
void UN00dFootstepsComponent::FootstepAudioFinished_Implementation()
{
	// ...
}

// handle audio finished
bool UN00dFootstepsComponent::RemoveFootstepFromActiveSound_Implementation()
{
	return false;
}

// get footprint
void UN00dFootstepsComponent::GetFootprint_Implementation(UMaterialInterface* &Footprint, FN00dFootstepsDecalSettings &Details)
{

}

// get random foley wave
void UN00dFootstepsComponent::GetRandomFootstepFoleyWave_Implementation(class USoundWave* &WaveToUse, float &AtVolume)
{

}

// get random surface wave
void UN00dFootstepsComponent::GetRandomFootstepSurfaceWave_Implementation(class USoundWave* &WaveToUse)
{

}

// get current footstep effect
void UN00dFootstepsComponent::GetCurrentFootstepEffect_Implementation(EPhysicalSurface ForSurface, FN00dFootstepsEffectMap& Effect)
{
}


// CHECKS

// mesh check 
bool UN00dFootstepsComponent::FootstepsMeshCheck_Implementation(class USkeletalMeshComponent* ActiveMesh)
{
	return false;
}

// SETTERS

// set foley 
void UN00dFootstepsComponent::SetFootstepFoley_Implementation(const struct FGameplayTag FoleyType)
{

}

// set should foley
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

// set footprint 
void UN00dFootstepsComponent::SetFootprint_Implementation(struct FGameplayTag FootprintType)
{
	//... 
}

// set speed
void UN00dFootstepsComponent::SetFootstepsSpeed_Implementation(struct FGameplayTag Speed)
{
	//...
}

// set decal rotation
bool UN00dFootstepsComponent::SetFootstepDecalRotation_Implementation()
{
	return false;
}

// set mesh component
bool UN00dFootstepsComponent::ConstructFootstepsMesh_Implementation(class USkeletalMeshComponent* Mesh)
{
	return false;
}

// get footsteps settings
void UN00dFootstepsComponent::GetFootstepsSettings(UN00dFootstepsSettings*& FootstepsSettings)
{
	UN00dFootstepsSettings* Settings = GetMutableDefault<UN00dFootstepsSettings>();
	FootstepsSettings = Settings;
}

