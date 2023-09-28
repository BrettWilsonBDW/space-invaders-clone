#include "GameLoop.hpp"

GameLoop::GameLoop()
{
    Init();
}

void GameLoop::Init()
{
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_VSYNC_HINT);
    //
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    SetExitKey(KEY_NULL);
    // SetTargetFPS(60);

    debug.SetFont(assetManager.GetFont());

    assetManager.SetGameUtils(&gameUtils);
    sceneManager.SetGameUtils(&gameUtils);
    sceneManager.SetAssetManager(&assetManager);
    player.SetAssetManager(&assetManager);
    player.SetGameUtils(&gameUtils);
    sceneManager.SetPlayer(&player);
    sceneManager.InitScenes();
    player.Init();
}

void GameLoop::Unload()
{
    // unload assets
    UnloadTexture(assetManager.Getlogo());
    UnloadFont(assetManager.GetFont());

    sceneManager.Unload();
    player.Unload();
}

void GameLoop::Update()
{
    player.UpdatePlayer();
    player.playerControls();
}

void GameLoop::UpdateWhilePaused()
{
    gameUtils.UpdateDeltaTime();
    gameUtils.CalcScale(width, height);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
    sceneManager.SetWindowInfo(windowWidth, windowHeight);
    player.updatePlayerPersistance();
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
        debug.PassItems("H: %d\n", GetScreenHeight());
        debug.PassItems("W: %d\n", GetScreenWidth());
        debug.PassItems("DT: %f\n", gameUtils.GetDeltaTime());
        debug.DrawItems(3, 3, 16, 0, 2, RED);

        DrawRectangleLines(player.GetPlayerRect().x, player.GetPlayerRect().y, player.GetPlayerRect().width, player.GetPlayerRect().height, RED);
    }
}

void GameLoop::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    if (!isPaused)
    {
        // sceneManager.SplashScreen();
        sceneManager.GameScreen();
    }

    if (isPaused)
    {
        sceneManager.PauseMenu();
    }

    if (useDebug == 0)
    {
        DebugStatements();
    }
    EndDrawing();
}

void GameLoop::MainLoopHelper(void *userData)
{
    GameLoop *gameLoop = static_cast<GameLoop *>(userData);

    if (IsKeyPressed(KEY_ESCAPE))
    {
        gameLoop->isPaused = !gameLoop->isPaused;
    }

    if (!gameLoop->isPaused)
    {
        gameLoop->Update();
    }

    gameLoop->UpdateWhilePaused();
    gameLoop->Draw();
}

void GameLoop::Run()
{
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop_arg(MainLoopHelper, this, 0, true);
#else

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            isPaused = !isPaused;
        }

        if (!isPaused)
        {
            Update();
        }

        UpdateWhilePaused();
        Draw();
    }

#endif
}
