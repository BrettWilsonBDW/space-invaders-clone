#include "GameLoop.hpp"

#include "../assets/testAssets/logo.h"

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

    // pack assets
    // gameUtils.packTexture("assets/testAssets/logo.png", "../assets/testAssets/logo.h");
    // gameUtils.packFont("assets/testAssets/Roboto.ttf", "../assets/testAssets/Roboto.h");

    // load assets
    logo = gameUtils.LoadImgFromFile(LOGO_DATA, LOGO_WIDTH, LOGO_HEIGHT, LOGO_FORMAT);

#if defined(PLATFORM_WEB)
    font = LoadFont("assets/fonts/Roboto.ttf");
#else
    font = gameUtils.LoadFontFromFile();
#endif

    debug.SetFont(font);

    gameScene.SetGameUtils(&gameUtils);
    gameScene.SetFont(font);
    gameScene.SetImgData(logo);
}

void GameLoop::Unload()
{
    UnloadTexture(logo);
    UnloadFont(font);
}

void GameLoop::Update()
{
    gameUtils.CalcScale(width, height);

    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
    // SetWindowSize(windowWidth, windowHeight);

    //update live window info for pos adjustments
    gameScene.SetWindowInfo(windowWidth, windowHeight);
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

    gameScene.SplashScreen();

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
