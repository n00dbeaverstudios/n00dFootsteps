// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Engine/Engine.h"
#include "Math/Color.h"
#include "Sound/SoundCue.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"

#include "FN00dFootstepsTypes.generated.h"



USTRUCT(BlueprintType)
struct FN00dFootstepsData : public FTableRowBase
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
struct FN00dFootstepsDecalSettings
{
	GENERATED_BODY()

	// Multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Size;
	// Destroy decal component when the time runs out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Lifetime;
	// The base opacity this footprint should be - fades to 0 then kills
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Opacity;
	// When to start fading the footprint out of existence. A fade of 0 and N duration = instant destroy footprint after N time has passed. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Fade;
	// The duration it takes for the decal to fade out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Duration;
	// Tint of the decal for this surface type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		struct FLinearColor Colour;

	// Default Constructor
	FN00dFootstepsDecalSettings()
	{
		Size = 1.0f;
		Lifetime = 3.0f;
		Opacity = 1.0f;
		Fade = 3.0f;
		Duration = 3.0f;
		Colour = FLinearColor();
	}
};

USTRUCT(BlueprintType)
struct FN00dFootstepsFootprints
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		FN00dFootstepsDecalSettings Settings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		class UMaterialInterface* LeftFoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		class UMaterialInterface* RightFoot;

	// Default Constructor
	FN00dFootstepsFootprints()
	{
		RightFoot = nullptr;
		LeftFoot  = nullptr;
	}
};

USTRUCT(BlueprintType)
struct FN00dFootstepsEffectMap : public FTableRowBase
{
	GENERATED_BODY()

		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		TEnumAsByte<EPhysicalSurface> Surface;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		class UParticleSystem* CascadeEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		class UNiagaraSystem* NiagaraEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		TArray<UMaterialInterface*> Materials;
	// Any sounds for this surface definition - the MasterCUE will play these
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		TArray<USoundWave*> Waves;
	// Footprint settings and definitions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		TMap<struct FGameplayTag, struct FN00dFootstepsFootprints> Footprints;

	// Default Constructor
	FN00dFootstepsEffectMap()
	{
		CascadeEffect = nullptr;
		NiagaraEffect = nullptr;
	}

};

USTRUCT(BlueprintType)
struct FN00dFootstepsWavesVolume
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		float Volume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = default)
		TArray<USoundWave*> Waves;

	// Default Constructor
	FN00dFootstepsWavesVolume()
	{
		Volume = 1.0f;
	}

};
