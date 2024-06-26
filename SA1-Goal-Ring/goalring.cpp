#include "pch.h"

//  Textures:

NJS_TEXNAME TEX_GoalRing[3] = { 0 };
NJS_TEXLIST TEXLIST_GoalRing = { arrayptrandlength(TEX_GoalRing) };

PVMEntry PVM_GoalRing = { "SA1_GoalRing", &TEXLIST_GoalRing };


//	Models & Collision:

ModelInfo* MDL_GoalRing = nullptr;

CCL_INFO COL_GoalRing = { 0, CollisionShape_Sphere, 0xF0, 0x20, 0x400, { 0.0f, 17.5f, 0.0f }, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };

NJS_POINT3 POS_GoalTrigger = { 0, 0, 0 };
float SCL_GoalTrigger = 20.0f;


//  Get Player ID from the custom sphere trigger:

uint32_t GetPlayerID()
{
    uint32_t PlayerID = IsPlayerInSphere(&POS_GoalTrigger, SCL_GoalTrigger) - 1;

    return PlayerID;
}


//	Goal Ring - Display:

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
    njRotateY(0, -twp->ang.y);
    
    DrawModel(MDL_GoalRing->getmodel()->basicdxmodel); // Outer Ring
    late_DrawModel(MDL_GoalRing->getmodel()->child->basicdxmodel, LATE_LIG); // Inner Ring (Background)
    late_DrawModel(MDL_GoalRing->getmodel()->child->sibling->basicdxmodel, LATE_LIG); // Inner Ring (Text)
    
    njPopMatrix(1u);
}


//  Goal Ring - Sub-Exec functions for co-op mode, battle mode and singleplayer mode: 

void COOP_GoalRing(task* tp)
{
    auto twp = tp->twp;
    auto PlayerID = GetPlayerID();

    if (CurrentCharacter == Characters_Tails)
    {
        if (IsPlayerInSphere(&POS_GoalTrigger, SCL_GoalTrigger))
        {
            if (PlayerID != AISonk_ID)
            {
                SetTailsRaceVictory();
                LoadLevelResults();

                twp->mode = 2;
            }

            else
            {
                StartLevelCutscene(1); // This function kicks you out back to the co-op stage select screen.

                twp->mode = 2;
            }
        }
    }
    
    else if (IsPlayerInSphere(&POS_GoalTrigger, SCL_GoalTrigger))
    {
        LoadLevelResults();
        
        twp->mode = 2;
    }
}

void BATTLE_GoalRing(task* tp)
{
    auto twp = tp->twp;   
    auto PlayerID = GetPlayerID();

    if (IsPlayerInSphere(&POS_GoalTrigger, SCL_GoalTrigger))
    {
        multi_set_winner(PlayerID);
        LoadLevelResults();

        twp->mode = 2;
    }
}

void SINGLEPLAYER_GoalRing(task* tp)
{
    auto twp = tp->twp;
    auto PlayerID = GetPlayerID();

    if (CurrentCharacter == Characters_Tails)
    {
        if (IsPlayerInSphere(&POS_GoalTrigger, SCL_GoalTrigger))
        {
            if (PlayerID != 1)
            {
                SetTailsRaceVictory();
                LoadLevelResults();

                twp->mode = 2;
            }

            else
            {
                SetOpponentRaceVictory();
                LoadLevelResults();

                twp->mode = 2;
            }
        }
    }

    else if (IsPlayerInSphere(&POS_GoalTrigger, SCL_GoalTrigger))
    {
        LoadLevelResults();

        twp->mode = 2;
    }
}

void FUNC_GoalRing(task* tp) // This is the main function that groups all the sub-exec functions, it's the one that will be called on the goal ring main exec.
{
    auto twp = tp->twp;
    
    if (SADX_Multiplayer)
    {
        if (multi_is_coop())
            COOP_GoalRing(tp);

        else if (multi_is_battle())
            BATTLE_GoalRing(tp);

        else
            SINGLEPLAYER_GoalRing(tp);
    }

    else
        SINGLEPLAYER_GoalRing(tp);
}


//  Goal Ring - Main Exec & Init:

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

            FUNC_GoalRing(tp);
            
            DrawShadow((EntityData1*)twp, 1.0f);
            twp->ang.y -= 500;
            
            EntryColliList(twp);

            break;
    }

    tp->disp(tp);
}

void INIT_GoalRing(task* tp)
{
    auto twp = tp->twp;

    tp->exec = EXEC_GoalRing;
    tp->disp = DISPLAY_GoalRing;
}


//	Goal Ring - Load Assets:

void LOAD_GoalRing()
{
	MDL_GoalRing = LoadBasicModel("SA1_GoalRing");

    HelperFunctionsGlobal.RegisterCommonObjectPVM(PVM_GoalRing); // Registers the Goal Ring PVM to the Common Objects PVM list.

    WriteJump((void*)0x46B170, INIT_GoalRing); // Replace Capsule Main Function
}