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

    debug.setFont(font);

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    // pack assets
    // gameUtils.packTexture("assets/testAssets/logo.png", "../assets/testAssets/logo.h");
    // gameUtils.packFont("assets/testAssets/Roboto.ttf", "../assets/testAssets/Roboto.h");

    // load assets
    logo = gameUtils.LoadImgFromFile(LOGO_DATA, LOGO_WIDTH, LOGO_HEIGHT, LOGO_FORMAT);

    font = gameUtils.LoadFontFromFile();
}

void GameLoop::Update()
{
    gameUtils.CalcScale(width, height);

    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
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

    // DrawTexture(logo, windowWidth / 2 - logo.width / 2, windowHeight / 2 - logo.height / 2, WHITE);

    // Vector2 windowCenter{(static_cast<float>(windowWidth) / 2) - logo.width, static_cast<float>(windowHeight) / 2};
    // DrawTextureEx(logo, windowCenter, 0, gameUtils.GetScale(), WHITE);

    float logoSacle = gameUtils.GetScale() / 3;
    Vector2 logoCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), (static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)};
    DrawTextureEx(logo, logoCenter, 0, logoSacle, WHITE);

    // Vector2 logoTextCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), ((static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)) + logo.height * logoSacle};
    // DrawTextEx(font, "© 2023 | Made by Brett Wilson", logoTextCenter, 16, 2, WHITE);

    std::string text = u8"\u00A9 2023 | Made by Brett Wilson";
    Vector2 logoTextCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), (((static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)) + logo.height * logoSacle) + 20};
    float centerX = logoTextCenter.x + (logo.width * logoSacle / 2);
    logoTextCenter.x = centerX - MeasureTextEx(font, text.c_str(), 16, 2).x / 2;
    DrawTextEx(font, text.c_str(), logoTextCenter, 16, 2, WHITE);

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
