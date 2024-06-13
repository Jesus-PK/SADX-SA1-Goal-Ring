#include "pch.h"

//	Mod Version: 1.0.0

std::string ModPath;
HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		ModPath = path;
		HelperFunctionsGlobal = helperFunctions;

		CheckActiveMods();
		CheckSA2GoalRing();

		
		//	Init Mod:

		LOAD_GoalRing();
		INIT_Graphics();
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}