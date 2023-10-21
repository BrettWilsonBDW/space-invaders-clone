#include "raylib.h"
#include "Debug.h"
#include "GameLoop.hpp"

// #if !defined(PLATFORM_WEB)
// #ifdef __cplusplus
// extern "C" {
// #endif
// #endif

//   __declspec(dllexport) unsigned long NvOptimusEnablement = 1;
//   __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

// #ifdef __cplusplus
// }
// #endif

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION 100
#endif

int main()
{
    int width = 1920 / 2;
    int height = 1080 / 2;

    // height = 1080 / 1.080;
    // width = 1920 / 1.080;

#if defined(PLATFORM_WEB)
    width = 1920 / 1.080;
    height = 1080 / 1.080;
#endif

    // height = 1080;
    // width = 1920;

    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(width, height, "Space Invaders");


    //gameloop handles calling all other classes as well web build
    GameLoop gameLoop;

    gameLoop.Run();

    gameLoop.Unload();

    CloseWindow();

    return 0;
}
