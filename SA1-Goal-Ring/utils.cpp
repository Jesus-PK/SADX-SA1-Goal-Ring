#include "pch.h"

//	Bools and code to check if certain mods or config options are enabled:

bool HD_GUI = false;
bool SADX_Multiplayer = false;

void CheckActiveMods()
{
	HD_GUI = HelperFunctionsGlobal.Mods->find("sadx-hd-gui") != nullptr;
    SADX_Multiplayer = HelperFunctionsGlobal.Mods->find("sadx-multiplayer") != nullptr;
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


//  Functions for a custom sphere check:

float GetDistance(NJS_VECTOR* v1, NJS_VECTOR* v2)
{
    return sqrtf((v2->x - v1->x) * (v2->x - v1->x) +
        (v2->y - v1->y) * (v2->y - v1->y) +
        (v2->z - v1->z) * (v2->z - v1->z));
}

int IsPlayerInSphere(NJS_POINT3* p, float r)
{
    for (int i = 0; i < PLAYER_MAX; ++i)
    {
        if (playertwp[i])
        {
            if (GetDistance(&playertwp[i]->pos, p) < r)
            {
                return i + 1;
            }
        }
    }

    return 0;
}