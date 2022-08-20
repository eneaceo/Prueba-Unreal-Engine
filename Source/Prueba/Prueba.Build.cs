// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Prueba : ModuleRules
{
	public Prueba(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
