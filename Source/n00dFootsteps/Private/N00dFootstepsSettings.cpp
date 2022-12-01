// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 


#include "N00dFootstepsSettings.h"

UN00dFootstepsSettings::UN00dFootstepsSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// initialise defaults

    static ConstructorHelpers::FObjectFinder<USoundCue> SoundObj(TEXT("/n00dFootsteps/Audio/A_N00dFootstepsMaster_CUE"));
    MasterSound = SoundObj.Object;

}