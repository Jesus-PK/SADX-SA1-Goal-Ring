#include "pch.h"

//	Bools and code to check if certain mods or config options are enabled:

bool HD_GUI = false;
bool DC_Conversion = false;

void CheckActiveMods()
{
	HD_GUI = HelperFunctionsGlobal.Mods->find("sadx-hd-gui") != nullptr;
	DC_Conversion = HelperFunctionsGlobal.Mods->find("sadx-dreamcast-conversion") != nullptr;
}


//	Function for loading Basic Models:

ModelInfo* LoadBasicModel(const char* name)
{
    PrintDebug("[SA1-Goal-Ring] Loading basic model: %s... ", name);

    std::string fullPath = "system\\models\\";
    fullPath = fullPath + name + ".sa1mdl";

    ModelInfo* mdl = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

    if (mdl->getformat() != ModelFormat_Basic)
    {
        PrintDebug("Failed!\n");

        delete mdl;
        return nullptr;
    }

    PrintDebug("Done!\n");

    return mdl;
}