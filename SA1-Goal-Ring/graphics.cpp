#include "pch.h"

//	Mission Cards:

void MISSIONCARDS_GoalRing()
{
	std::string EN_Index = ModPath;
	std::string JP_Index = ModPath;

	if (HD_GUI)
	{
		EN_Index += "\\textures\\EN_MissionCards_HD\\index.txt";
		const char* HD_EN_Index = EN_Index.c_str();

		ReplacePVR("MISSION_S_BOX_E", HD_EN_Index);
		ReplacePVR("MISSION_S_BOX2MIN_E", HD_EN_Index);
		ReplacePVR("MISSION_S_BOX3MIN_E", HD_EN_Index);
		ReplacePVR("MISSION_S_BOX4MIN_E", HD_EN_Index);
		ReplacePVR("MISSION_S_BOX5MIN_E", HD_EN_Index);
		ReplacePVR("MISSION_S_BOX25MIN_E", HD_EN_Index);
		ReplacePVR("MISSION_S_BOX45MIN_E", HD_EN_Index);
		ReplacePVR("MISSION_S_RINGBOX_E", HD_EN_Index);
		ReplacePVR("MISSION_T_BOX_E", HD_EN_Index);


		JP_Index += "\\textures\\JP_MissionCards_HD\\index.txt";
		const char* HD_JP_Index = JP_Index.c_str();
		
		ReplacePVR("MISSION_S_2MIN", HD_JP_Index);
		ReplacePVR("MISSION_S_2MINH", HD_JP_Index);
		ReplacePVR("MISSION_S_3MIN", HD_JP_Index);
		ReplacePVR("MISSION_S_4MIN", HD_JP_Index);
		ReplacePVR("MISSION_S_4MINH", HD_JP_Index);
		ReplacePVR("MISSION_S_5MIN", HD_JP_Index);
		ReplacePVR("MISSION_S_BOX", HD_JP_Index);
		ReplacePVR("MISSION_S_BOXMIN", HD_JP_Index);
		ReplacePVR("MISSION_S_RINGBOX", HD_JP_Index);
		ReplacePVR("MISSION_T_BOX", HD_JP_Index);		
	}

	else
	{
		EN_Index += "\\textures\\EN_MissionCards_SD\\index.txt";
		const char* SD_EN_Index = EN_Index.c_str();

		ReplacePVR("MISSION_S_BOX_E", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX2MIN_E", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX3MIN_E", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX4MIN_E", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX5MIN_E", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX25MIN_E", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX45MIN_E", SD_EN_Index);
		ReplacePVR("MISSION_S_RINGBOX_E", SD_EN_Index);
		ReplacePVR("MISSION_T_BOX_E", SD_EN_Index);

		ReplacePVR("MISSION_S_BOX_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX2MIN_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX3MIN_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX4MIN_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX5MIN_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX25MIN_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_BOX45MIN_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_S_RINGBOX_E_DC", SD_EN_Index);
		ReplacePVR("MISSION_T_BOX_E_DC", SD_EN_Index);


		JP_Index += "\\textures\\JP_MissionCards_SD\\index.txt";
		const char* SD_JP_Index = JP_Index.c_str();

		ReplacePVR("MISSION_S_2MIN", SD_JP_Index);
		ReplacePVR("MISSION_S_2MINH", SD_JP_Index);
		ReplacePVR("MISSION_S_3MIN", SD_JP_Index);
		ReplacePVR("MISSION_S_4MIN", SD_JP_Index);
		ReplacePVR("MISSION_S_4MINH", SD_JP_Index);
		ReplacePVR("MISSION_S_5MIN", SD_JP_Index);
		ReplacePVR("MISSION_S_BOX", SD_JP_Index);
		ReplacePVR("MISSION_S_BOXMIN", SD_JP_Index);
		ReplacePVR("MISSION_S_RINGBOX", SD_JP_Index);
		ReplacePVR("MISSION_T_BOX", SD_JP_Index);

		ReplacePVR("MISSION_S_2MIN_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_2MINH_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_3MIN_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_4MIN_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_4MINH_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_5MIN_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_BOX_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_BOXMIN_DC", SD_JP_Index);
		ReplacePVR("MISSION_S_RINGBOX_DC", SD_JP_Index);
		ReplacePVR("MISSION_T_BOX_DC", SD_JP_Index);
	}
}


//	Init Graphics:

void INIT_Graphics()
{
	MISSIONCARDS_GoalRing();
}