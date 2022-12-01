// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

using UnrealBuildTool;

public class n00dFootsteps : ModuleRules
{
	public n00dFootsteps(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Engine",
                "InputCore",
                "UMG",
                "GameplayTags",
				"Niagara"
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
			);

        if (Target.Version.MinorVersion != 25)
        {
            PublicDependencyModuleNames.Add("PhysicsCore");
        };
    }

}

