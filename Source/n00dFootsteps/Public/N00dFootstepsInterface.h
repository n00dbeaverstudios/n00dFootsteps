/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "N00dFootstepsComponent.h"

#include "N00dFootstepsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UN00dFootstepsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class N00DFOOTSTEPS_API IN00dFootstepsInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Footstep
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dFootstep (FN00dFootstepsData Data, class USkeletalMeshComponent* Mesh);

	// The current physical surface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dDebugFootstepsSurface(EPhysicalSurface Type);
	// The number of active sounds
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dDebugFootstepsActiveSounds(int32 NumCurrentlyActive);
	// The speed we are at
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dDebugFootstepsSpeed(FGameplayTag Speed);
	// The sound to play alongside the footsteps
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dDebugFootstepsFoley(FGameplayTag Foley);
	// A decal representing the footprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dDebugFootstepsFootprint(FGameplayTag Footprint);
	// Set the foot side
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Footsteps|Interface")
		void N00dDebugFootstepsFoot(bool LeftFoot);


};
