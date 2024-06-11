#pragma once

//	Macros:

#define ReplaceTEX(pvm, tex_name, folder, png_name, gbix, width, height) HelperFunctionsGlobal.ReplaceTexture(pvm, tex_name, (std::string(ModPath) + "\\textures\\" folder "\\" png_name ".png").c_str(), gbix, width, height);
#define ReplacePVR(a, b) HelperFunctionsGlobal.ReplaceFile("system\\" a ".PVR", b);


//	Bools and code to check if certain mods or config options are enabled:

extern bool HD_GUI;
extern bool Multiplayer;

void CheckActiveMods();


//	Functions for loading Models and Animations:

ModelInfo* LoadBasicModel(const char* name);


//  Functions for a custom Sphere check:

#define PLAYER_MAX 4

float GetDistance(NJS_VECTOR* v1, NJS_VECTOR* v2);
int IsPlayerInSphere(NJS_POINT3* p, float r);


//	CollisionShapes enums:

enum CollisionShapes
{
	CollisionShape_Sphere,		// A		|	(Radius)
	CollisionShape_Cylinder,	// A, B		|	(Radius, Height)
	CollisionShape_Cylinder2,	// A, B		|	(Radius, Height)
	CollisionShape_Cube,		// A, B, C	|	(XYZ Scale)
	CollisionShape_Cube2,		// A, B, C	|	(XYZ Scale - Support YZ rotation)
	CollisionShape_Capsule = 6,	// A, B		|	(Radius, Height - Support XYZ rotation - Cylinder with rounded ends that can't be walked on),
	CollisionShape_PushWall = 9	// A, B, C	|	(Width, Height, Power - A wall that pushes the player - Support Y rotation)
};