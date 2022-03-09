/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Engine/Engine.h"
#include "Math/Color.h"
#include "Sound/SoundCue.h"
#include "GameplayTagContainer.h"

#include "FN00dFootstepsTypes.generated.h"



USTRUCT(BlueprintType)
struct FN00dFootstepsData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		FName Socket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		bool LeftFoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float DifferentialStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float DifferentialEnd;

	// Default Constructor
	FN00dFootstepsData()
	{
		LeftFoot = false;
		DifferentialStart = 25.0f;
		DifferentialEnd = -25.0f;
	}


};

USTRUCT(BlueprintType)
struct FDebugOptions
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		bool PrintToWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		FGameplayTag DebugType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		FColor TextColour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Duration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		bool PrintToScreen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		bool PrintToLog;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		FString Append;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		bool AppendAsSuffix;

};

USTRUCT(BlueprintType)
struct FN00dFootstepsDecalSettings
{
	GENERATED_BODY()

	// Multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Footsteps|Decal Settings")
		float Size;
	// Destroy decal component when the time runs out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Footsteps|Decal Settings")
		float Lifetime;
	// The base opacity this footprint should be - fades to 0 then kills
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Footsteps|Decal Settings")
		float Opacity;
	// When to start fading the footprint out of existence. A fade of 0 and N duration = instant destroy footprint after N time has passed. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Footsteps|Decal Settings")
		float Fade;
	// The duration it takes for the decal to fade out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Footsteps|Decal Settings")
		float Duration;
	// Tint of the decal for this surface type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents|Footsteps|Decal Settings")
		struct FLinearColor Colour;

	// Default Constructor
	FN00dFootstepsDecalSettings()
	{
		Size = 1.0f;
		Lifetime = 3.0f;
		Opacity = 1.0f;
		Fade = 3.0f;
		Duration = 3.0f;
	}
};

USTRUCT(BlueprintType)
struct FN00dFootstepsFootprints
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Footprints")
		FN00dFootstepsDecalSettings Settings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Footprints")
		class UMaterialInterface* LeftFoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Footprints")
		class UMaterialInterface* RightFoot;

	// Default Constructor
	FN00dFootstepsFootprints()
	{
		RightFoot = nullptr;
		LeftFoot  = nullptr;
	}
};

USTRUCT(BlueprintType)
struct FN00dFootstepsEffectMap
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Effect Map")
		class UParticleSystem* CascadeEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Effect Map")
		class UNiagaraSystem* NiagaraEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Effect Map")
		TArray<UMaterialInterface*> Materials;
	// The MasterCUE is where the system sets parameters such as Foley, but you can use your own instead if desired.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Effect Map")
		class USoundCue* Sound;
	// Any sounds for this surface definition - the MasterCUE will play these
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Effect Map")
		TArray<USoundWave*> Waves;
	// Footprint settings and definitions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Effect Map")
		TMap<struct FGameplayTag, struct FN00dFootstepsFootprints> Footprints;

	// Default Constructor
	FN00dFootstepsEffectMap()
	{
		CascadeEffect = nullptr;
		NiagaraEffect = nullptr;
		Sound = nullptr;
	}

};

USTRUCT(BlueprintType)
struct FN00dFootstepsWavesVolume
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Waves Volume")
		float Volume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "N00dComponents |Footsteps |Waves Volume")
		TArray<USoundWave*> Waves;

	// Default Constructor
	FN00dFootstepsWavesVolume()
	{
		Volume = 1.0f;
	}

};
