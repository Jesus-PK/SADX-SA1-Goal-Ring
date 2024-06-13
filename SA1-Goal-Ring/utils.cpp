#include "pch.h"

//	Bools and code to check if certain mods or config options are enabled:

bool HD_GUI = false;
bool SADX_Multiplayer = false;
bool SA2_GoalRing = false;

void CheckActiveMods()
{
	HD_GUI = HelperFunctionsGlobal.Mods->find("sadx-hd-gui") != nullptr;
    SADX_Multiplayer = HelperFunctionsGlobal.Mods->find("sadx-multiplayer") != nullptr;

    SA2_GoalRing = GetModuleHandle(L"GoalRing") != nullptr;
}

void CheckSA2GoalRing()
{
    if (SA2_GoalRing)
    {
        MessageBox(WindowHandle,
            L"WARNING! The (Goal Ring Mod) has been enabled at the same time as the (SA1 Goal Ring) mod.\n\nThese mods are standalone works and do not require each other to work. Keeping both enabled might cause compatibility issues.\n\nPlease exit the game, disable either of them, then try again.",
            L"SA1 Goal Ring: Compatibility Warning", MB_OK | MB_ICONERROR);
    }
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