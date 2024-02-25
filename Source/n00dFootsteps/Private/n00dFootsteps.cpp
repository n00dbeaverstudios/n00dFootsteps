// Copyright Epic Games, Inc. All Rights Reserved.

#include "n00dFootsteps.h"

#define LOCTEXT_NAMESPACE "Fn00dFootstepsModule"

void Fn00dFootstepsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void Fn00dFootstepsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dFootstepsModule, n00dFootsteps)