// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GreenPieceTarget : TargetRules
{
	public GreenPieceTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GreenPiece");
	}
}
