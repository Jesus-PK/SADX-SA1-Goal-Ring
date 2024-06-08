#pragma once

//	Macros:

#define ReplaceTEX(pvm, tex_name, folder, png_name, gbix, width, height) HelperFunctionsGlobal.ReplaceTexture(pvm, tex_name, (std::string(ModPath) + "\\textures\\" folder "\\" png_name ".png").c_str(), gbix, width, height);
#define ReplacePVR(a, b) HelperFunctionsGlobal.ReplaceFile("system\\" a ".PVR", b);


//	Bools and code to check if certain mods or config options are enabled:

extern bool HD_GUI;
extern bool DC_Conversion;

void CheckActiveMods();


//	Functions for loading Models and Animations:

ModelInfo* LoadBasicModel(const char* name);