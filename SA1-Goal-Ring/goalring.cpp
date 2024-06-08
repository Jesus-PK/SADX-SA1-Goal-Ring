#include "pch.h"

NJS_TEXNAME TEX_GoalRing[3] = { 0 };
NJS_TEXLIST TEXLIST_GoalRing = { arrayptrandlength(TEX_GoalRing) };

//	Models & Collision:

ModelInfo* MDL_GoalRing = nullptr;

NJS_POINT3 POS_ExitTrigger = { 0, 0, 0 };


//	Goal Ring - Main:

void DISPLAY_GoalRing(task* tp)
{
	if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_GoalRing);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_GoalRing->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_GoalRing(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            POS_ExitTrigger.x = twp->pos.x;
            POS_ExitTrigger.y = twp->pos.y + 10.25f;
            POS_ExitTrigger.z = twp->pos.z;

            twp->mode++;

            break;

        case 1:

            twp->ang.y += 500;

            if (CheckCollisionP(&POS_ExitTrigger, 12.0f))
            {
                LoadLevelResults();

                twp->mode = 2;
            }

            break;
    }

    tp->disp(tp);
}

void INIT_GoalRing(task* tp)
{
    auto twp = tp->twp;

    tp->exec = EXEC_GoalRing;
    tp->disp = DISPLAY_GoalRing;

    LoadPVM("SA1_GoalRing", &TEXLIST_GoalRing);
}


//	Goal Ring - Load Assets:

void LOAD_GoalRing()
{
	MDL_GoalRing = LoadBasicModel("SA1_GoalRing");

    WriteJump((void*)0x46B170, INIT_GoalRing); // Replace Capsule Main Function
}