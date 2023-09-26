#include "raylib.h"
#include "Debug.h"
#include "GameLoop.hpp"

int main()
{
    int width = 1920 / 2;
    int height = 1080 / 2;
    InitWindow(width, height, "Space Invaders");

    GameLoop gameLoop;

    gameLoop.Run();

    CloseWindow();

    return 0;
}
