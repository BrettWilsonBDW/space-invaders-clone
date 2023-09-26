#include "raylib.h"
#include "Debug.h"
#include "GameLoop.hpp"

int main()
{
    int width = 1920;
    int height = 1080;
    InitWindow(width / 2, height / 2, "Game name");

    GameLoop gameLoop;

    gameLoop.Run();

    CloseWindow();

    return 0;
}
