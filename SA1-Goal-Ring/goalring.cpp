#include "pch.h"

//  Textures:

NJS_TEXNAME TEX_GoalRing[3] = { 0 };
NJS_TEXLIST TEXLIST_GoalRing = { arrayptrandlength(TEX_GoalRing) };


//	Models & Collision:

ModelInfo* MDL_GoalRing = nullptr;

CCL_INFO COL_GoalRing = { 0, 0x0, 0xF0, 0x20, 0x400, { 0.0f, 17.5f, 0.0f }, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };

NJS_POINT3 POS_GoalTrigger = { 0, 0, 0 };


//	Goal Ring - Main:

void DISPLAY_GoalRing(task* tp)
{
	if (MissedFrames)
        return;

    auto twp = tp->twp;

    if (twp->mode == 2)
        return;

    njSetTexture(&TEXLIST_GoalRing);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y + 5.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    DrawModel(MDL_GoalRing->getmodel()->basicdxmodel);
    late_DrawModel(MDL_GoalRing->getmodel()->child->basicdxmodel, LATE_LIG);
    
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

            CCL_Init(tp, &COL_GoalRing, 1, 2u);
            
            POS_GoalTrigger.x = twp->pos.x;
            POS_GoalTrigger.y = twp->pos.y + 17.5f;
            POS_GoalTrigger.z = twp->pos.z;

            twp->mode++;

            break;

        case 1:

            twp->ang.y += 500;

            if (CurrentCharacter == Characters_Tails)
            {
                switch (CheckCollisionP(&POS_GoalTrigger, 15.0f))
                {
                    case 0: // NO - Player ISN'T on sphere.
                        break;
                    case 1: // YES - Player IS on sphere.
                        SetTailsRaceVictory();
                        LoadLevelResults();
                        twp->mode = 2;
                        break;
                    default: // Default kicks in when Sonk catches the goal ring before Tails.
                        SetOpponentRaceVictory();
                        LoadLevelResults();
                        twp->mode = 2;
                        break;
                }
            }

            else if (CheckCollisionP(&POS_GoalTrigger, 15.0f))
            {
                LoadLevelResults();
                twp->mode = 2;
            }

            EntryColliList(twp);

            /*
            if (CheckCollisionP(&POS_GoalTrigger, 12.0f))
            {
                if (CurrentCharacter == Characters_Tails)
                {
                    SetTailsRaceVictory();
                    LoadLevelResults();

                    twp->mode = 2;
                }

                else
                {
                    LoadLevelResults();

                    twp->mode = 2;
                }
            }*/

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