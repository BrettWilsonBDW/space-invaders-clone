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

    debug.SetFont(assetManager.GetFont());

    assetManager.SetGameUtils(&gameUtils);
    sceneManager.SetGameUtils(&gameUtils);
    sceneManager.SetAssetManager(&assetManager);
    sceneManager.InitScenes();
}

void GameLoop::Unload()
{
    UnloadTexture(assetManager.Getlogo());
    UnloadFont(assetManager.GetFont());
}

void GameLoop::Update()
{
    gameUtils.CalcScale(width, height);

    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
    // SetWindowSize(windowWidth, windowHeight);

    //update live window info for pos adjustments
    sceneManager.SetWindowInfo(windowWidth, windowHeight);
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

    sceneManager.SplashScreen();

    if (useDebug == 0)
    {
        DebugStatements();
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
