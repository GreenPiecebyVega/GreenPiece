// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

using UnrealBuildTool;

public class GreenPiece : ModuleRules
{
	public GreenPiece(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG",
			"Http", "Json", "JsonUtilities"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"Slate", "SlateCore"
		});
	}
}
