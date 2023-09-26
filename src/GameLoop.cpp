#include "GameLoop.hpp"

GameLoop::GameLoop()
{
    Init();
}

void GameLoop::Init()
{
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    // gameUtils.CalcScale(width, height);
    debug.setFont(LoadFont("assets/fonts/Roboto.ttf"));

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

}

void GameLoop::Update()
{
    gameUtils.CalcScale(width, height);

    // windowWidth = GetScreenWidth();
    // windowHeight = GetScreenHeight();
    // SetWindowSize(windowWidth, windowHeight);
}

void GameLoop::DebugStatements()
{
    // debug  menu
    if (debug.ToggleState())
    {
        int fps = GetFPS();

        // call drawItems once and passItems before as many times as needed

        debug.PassItems("Debug Menu:\n");
        debug.PassItems("FPS: %d\n", fps);
        debug.PassItems("Scale: %f\n", gameUtils.GetScale());
        debug.DrawItems(3, 3, 16);
    }
}

void GameLoop::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
}

void GameLoop::MainLoopHelper(void *userData)
{
    GameLoop *gameLoop = static_cast<GameLoop *>(userData);

    if (gameLoop->useDebug == 0)
    {
        gameLoop->DebugStatements();
    }

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
        if (useDebug == 0)
        {
            DebugStatements();
        }

        Update();

        Draw();
    }
#endif
}
