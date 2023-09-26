#include "GameLoop.hpp"

GameLoop::GameLoop()
{
    Init();
}

void GameLoop::Init()
{
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    debug.setFont(LoadFont("assets/fonts/Roboto.ttf"));
}

void GameLoop::Update()
{
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
    SetWindowSize(windowWidth, windowHeight);
}

void GameLoop::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    // debug  menu
    if (debug.ToggleState())
    {
        int fps = GetFPS();

        // call drawItems once and passItems before as many times as needed

        debug.PassItems("Debug Menu:\n");
        debug.PassItems("FPS: %d\n", fps);
        debug.DrawItems(3, 3, 16);
    }

    EndDrawing();
}


void GameLoop::MainLoopHelper(void *userData)
{
    GameLoop *gameLoop = static_cast<GameLoop *>(userData);

    gameLoop->Update();
    gameLoop->Draw();
}

void GameLoop::Run()
{
#if defined(PLATFORM_WEB)

    emscripten_set_main_loop_arg(MainLoopHelper, this, 0, true);

#else
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

#endif
}
