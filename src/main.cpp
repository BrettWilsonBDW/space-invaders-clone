#include "raylib.h"
#include "Debug.h"
#include "GameLoop.hpp"

int main()
{
    int width = 1920 / 2;
    int height = 1080 / 2;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "Space Invaders");

    GameLoop gameLoop;

    gameLoop.Run();

    gameLoop.Unload();

    CloseWindow();

    return 0;
}
