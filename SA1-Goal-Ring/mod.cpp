#include "pch.h"

//	Mod Version: W.I.P

std::string ModPath;
HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		ModPath = path;
		HelperFunctionsGlobal = helperFunctions;

		CheckActiveMods();

		
		//	Init Mod:

		LOAD_GoalRing();
		INIT_Graphics();

		
		//	TESTING PURPOSES - PENDING REMOVAL:

		StartPosition STARTPOS_TreeTops00 = { LevelIDs_WindyValley, 2, { 5820.0f, -10700.0f, -735.0f }, 0x0};
		StartPosition STARTPOS_TreeTops01 = { LevelIDs_SkyDeck, 0, { 885.0f, -330.0f, 5478.0f }, 0x0 };
		HelperFunctionsGlobal.RegisterStartPosition(Characters_Tails, STARTPOS_TreeTops00);
		HelperFunctionsGlobal.RegisterStartPosition(Characters_Tails, STARTPOS_TreeTops01);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}