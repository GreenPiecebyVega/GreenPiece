// Green Piece - ID:929641795 Copyright © Vega Soft. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GreenPieceEditorTarget : TargetRules
{
	public GreenPieceEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GreenPiece");
	}
}
