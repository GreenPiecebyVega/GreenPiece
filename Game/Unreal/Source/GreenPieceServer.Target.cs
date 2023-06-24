// Green Piece - 929641795 Copyright © Vega Soft. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GreenPieceServerTarget : TargetRules
{
	public GreenPieceServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GreenPiece");
	}
}
