# SADX - SA1 Goal Ring (v1.0.0)

## Overview:

This mod replaces all Capsules in the game with SA1 Styled Goal Rings, it also includes custom Mission Cards and Multiplayer support. You can find more details about this mod in [**GameBanana**](https://gamebanana.com/mods/520367).

**Features:**
* A custom SA1 Styled Goal Ring model, edited from the official model used in the Y2K DLC. It replaces all instances of the vanilla Capsule in the game through code, so this mod supports custom levels if they use the vanilla Capsule as their end objective.
* Custom Mission Cards that reflect the change of objective. All of them having full English and Japanese support alongside SD and HD quality textures depending if you are using HD GUI or not.
* Multiplayer support. The Goal Ring fully supports Singleplayer, Co-Op and Battle modes.

## Compatibility Notes:
* This mod is a standalone package, it doesn't require any dependencies.
* It's recommended to load it on the bottom of the list (or at least below mods that might edit the vanilla Capsule model or functions such as Dreamcast Conversion).
* If you encounter any issues, you can use the [**Issues**](https://github.com/Jesus-PK/SADX-SA1-Goal-Ring/issues) tab or [**GameBanana**](https://gamebanana.com/mods/520367) page to report any issues.

## Repository Notes:

This repository hosts both the code and playable versions of this mod. You can find them in the [**Releases**](https://github.com/Jesus-PK/SADX-SA1-Goal-Ring/releases) tab or [**GameBanana**](https://gamebanana.com/mods/520367) page.

Cloning this repository should result in a buildable .dll project of this mod without any additional tweaks needed, though there's a few things worth noting:

* Make sure that you are compiling in **x86 mode**.
* The project uses custom include paths, the project settings already have setup the necessary additional include directories in **Project > Properties > C/C++ > General > Additional Include Directories** for both **Release - x86** and **Debug - x86** (All Configurations - Win32) - These are the include directories:

  * `$(ProjectDir)`
  * `$(ProjectDir)multiplayer`
  * `$(ProjectDir)programming`

* The files in the `multiplayer` folder are the Multiplayer API necessary files (`multiapi.h` and `sadx-multiplayer.lib`)

* The files in the `programming` folder are the same ones encountered in the `programming` folder that is shipped with the SADX Mod Loader. I copy these files manually at the time of creating my project and I also update them manually, so remember that you might need to replace them with "fresh" ones from the latest Mod Loader release from time to time when those files get updated.

* Adding to this, the following files need to be added to the existing **Source Files** of this project via the Project Properties window (**Source Files > Right Click > Add Existing Item**):

  * `ModelInfo.cpp`

* Regarding the Multiplayer API, these are the few extra settings that have been applied to the project to make everything work correctly:
  * **Linker > General > Additional Library Dependencies:**

    * `$(ProjectDir)`
    * `$(ProjectDir)multiplayer`

  * **Linker > Input > Additional Dependencies:**

    * `sadx-multiplayer.lib`

  * **Linker > Input > Delay Loaded DLLs**

    * `sadx-multiplayer.dll`
   
* As an extra, I have the project set it up so it automatically copies the new .DLLs on the mod folder everytime I build the code (so no need to copypaste it manually) - The target path needs to be adjusted depending on your game's path:

  * **Build Events > Post-Build Event > Command Line**

    * `xcopy "$(SolutionDir)Release\*.dll" "D:\Juegos\Retail\SONICADVENTUREDX\mods\SA1 Goal Ring\*.dll" /Y`

As always, it's recommended to make your own project from scratch and just use these functions and annotations you see in here as a guide / example to learn what they do instead of just cloning the repository or copypasting functions. I say this because some of these things might only apply to this mod in particular instead of a general level due to using specific nomenclatures / tweaks or they might just be wrong / obsolete as time goes by.

If you are looking for further help and troubleshooting, feel free to check out the [**X-Hax Discord**](https://discord.gg/gqJCF47).
