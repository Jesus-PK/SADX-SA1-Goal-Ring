#include "pch.h"

//	Mission Cards:

void MISSIONCARDS_GoalRing()
{
	std::string index = ModPath;

	if (HD_GUI)
	{
		index += "\\textures\\MissionCards_HD\\index.txt";
		const char* HD_Index = index.c_str();

		ReplacePVR("MISSION_S_BOX_E", HD_Index);
		ReplacePVR("MISSION_S_BOX2MIN_E", HD_Index);
		ReplacePVR("MISSION_S_BOX3MIN_E", HD_Index);
		ReplacePVR("MISSION_S_BOX4MIN_E", HD_Index);
		ReplacePVR("MISSION_S_BOX5MIN_E", HD_Index);
		ReplacePVR("MISSION_S_BOX25MIN_E", HD_Index);
		ReplacePVR("MISSION_S_BOX45MIN_E", HD_Index);
		ReplacePVR("MISSION_S_RINGBOX_E", HD_Index);
		ReplacePVR("MISSION_T_BOX_E", HD_Index);

		/*
		ReplacePVR("MISSION_S_2MIN", HD_Index);
		ReplacePVR("MISSION_S_2MINH", HD_Index);
		ReplacePVR("MISSION_S_3MIN", HD_Index);
		ReplacePVR("MISSION_S_4MIN", HD_Index);
		ReplacePVR("MISSION_S_4MINH", HD_Index);
		ReplacePVR("MISSION_S_5MIN", HD_Index);
		ReplacePVR("MISSION_S_BOX", HD_Index);
		ReplacePVR("MISSION_S_BOXMIN", HD_Index);
		ReplacePVR("MISSION_S_RINGBOX", HD_Index);
		ReplacePVR("MISSION_T_BOX", HD_Index);
		*/
	}

	else
	{
		index += "\\textures\\MissionCards_SD\\index.txt";
		const char* SD_Index = index.c_str();

		ReplacePVR("MISSION_S_BOX_E", SD_Index);
		ReplacePVR("MISSION_S_BOX2MIN_E", SD_Index);
		ReplacePVR("MISSION_S_BOX3MIN_E", SD_Index);
		ReplacePVR("MISSION_S_BOX4MIN_E", SD_Index);
		ReplacePVR("MISSION_S_BOX5MIN_E", SD_Index);
		ReplacePVR("MISSION_S_BOX25MIN_E", SD_Index);
		ReplacePVR("MISSION_S_BOX45MIN_E", SD_Index);
		ReplacePVR("MISSION_S_RINGBOX_E", SD_Index);
		ReplacePVR("MISSION_T_BOX_E", SD_Index);

		ReplacePVR("MISSION_S_BOX_E_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX2MIN_E_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX3MIN_E_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX4MIN_E_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX5MIN_E_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX25MIN_E_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX45MIN_E_DC", SD_Index);
		ReplacePVR("MISSION_S_RINGBOX_E_DC", SD_Index);
		ReplacePVR("MISSION_T_BOX_E_DC", SD_Index);

		/*
		ReplacePVR("MISSION_S_2MIN", SD_Index);
		ReplacePVR("MISSION_S_2MINH", SD_Index);
		ReplacePVR("MISSION_S_3MIN", SD_Index);
		ReplacePVR("MISSION_S_4MIN", SD_Index);
		ReplacePVR("MISSION_S_4MINH", SD_Index);
		ReplacePVR("MISSION_S_5MIN", SD_Index);
		ReplacePVR("MISSION_S_BOX", SD_Index);
		ReplacePVR("MISSION_S_BOXMIN", SD_Index);
		ReplacePVR("MISSION_S_RINGBOX", SD_Index);
		ReplacePVR("MISSION_T_BOX", SD_Index);

		ReplacePVR("MISSION_S_2MIN_DC", SD_Index);
		ReplacePVR("MISSION_S_2MINH_DC", SD_Index);
		ReplacePVR("MISSION_S_3MIN_DC", SD_Index);
		ReplacePVR("MISSION_S_4MIN_DC", SD_Index);
		ReplacePVR("MISSION_S_4MINH_DC", SD_Index);
		ReplacePVR("MISSION_S_5MIN_DC", SD_Index);
		ReplacePVR("MISSION_S_BOX_DC", SD_Index);
		ReplacePVR("MISSION_S_BOXMIN_DC", SD_Index);
		ReplacePVR("MISSION_S_RINGBOX_DC", SD_Index);
		ReplacePVR("MISSION_T_BOX_DC", SD_Index);
		*/
	}
}


//	Init Graphics:

void INIT_Graphics()
{
	MISSIONCARDS_GoalRing();
}