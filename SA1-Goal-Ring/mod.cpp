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

		

		
		//	Init Mod:

		LOAD_GoalRing();
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}