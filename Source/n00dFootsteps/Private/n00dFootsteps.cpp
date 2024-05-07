// Copyright Epic Games, Inc. All Rights Reserved.

#include "n00dFootsteps.h"

#define LOCTEXT_NAMESPACE "Fn00dFootstepsModule"

// Startup
void Fn00dFootstepsModule::StartupModule()
{
	RegisterSettings();
}

// Shutdown
void Fn00dFootstepsModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

/////////////////////////////////
// Overrides for ISettingsModule
/////////////////////////////////

// Support for dynamic reloading
bool Fn00dFootstepsModule::SupportsDynamicReloading()
{
	return true;
}

// Callback for when the settings were saved.
bool Fn00dFootstepsModule::HandleSettingsSaved()
{
	// Validation code to resave the settings in case an invalid value has been entered
	UN00dFootstepsSettings* Settings = GetMutableDefault<UN00dFootstepsSettings>();
	bool ResaveSettings = false;

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	return true;
}

// Register settings
void Fn00dFootstepsModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{

		// Registering some settings is just a matter of exposing the default UObject of
		// your desired class, these are the global settings we want to expose to LDs or artists.

			// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("n00d",
			LOCTEXT("RuntimeWDCategoryName", "n00d"),
			LOCTEXT("RuntimeWDCategoryDescription", "Global configuration for n00d assets"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "n00d", "Footsteps",
			LOCTEXT("RuntimeGeneralSettingsName", "Footsteps"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "n00dFootsteps Global Config"),
			GetMutableDefault<UN00dFootstepsSettings>()
		);

		// Register the save handler to our settings, we might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &Fn00dFootstepsModule::HandleSettingsSaved);
		}
	}
}

// Unregister settings
void Fn00dFootstepsModule::UnregisterSettings()
{
	// Ensure to unregister all of our registered settings here, hot-reload would
	// otherwise yield unexpected results.
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "n00d", "Footsteps");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dFootstepsModule, n00dFootsteps)