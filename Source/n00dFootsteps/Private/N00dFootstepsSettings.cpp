// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 


#include "N00dFootstepsSettings.h"

UN00dFootstepsSettings::UN00dFootstepsSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// initialise defaults

	// reference the master sound cue
	MasterSound = LoadObject<USoundCue>(NULL, TEXT("/n00dFootsteps/Core/A_N00dFootstepsMaster_CUE.A_N00dFootstepsMaster_CUE"), NULL, LOAD_None, NULL);

	// switch on the bools by default
	DebugFootsteps = true;
	UseDefaults = true;
	ShouldFoley = true;

}