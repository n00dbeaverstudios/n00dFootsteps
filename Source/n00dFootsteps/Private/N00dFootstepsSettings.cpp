// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2020-2024 - All Rights Reserved. 

#include "N00dFootstepsSettings.h"

UN00dFootstepsSettings::UN00dFootstepsSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// initialise defaults
	DebugFootsteps = false;
	DisableFootsteps = false;
}

UN00dFootstepsSettings* UN00dFootstepsSettings::GetFootstepsSettings()
{
	// Return the singleton instance of the settings class
	return GetMutableDefault<UN00dFootstepsSettings>();
}
