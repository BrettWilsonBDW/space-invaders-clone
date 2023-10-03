#include "GameLoop.hpp"

GameLoop::GameLoop()
{
    Init();
}

/**
 * Initializes the GameLoop.
 *
 * @throws ErrorType description of error
 */
void GameLoop::Init()
{
#if !defined(PLATFORM_WEB)
    SetTargetFPS(60); // never forget this... the web cant handle being locked to 60
#endif

    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_VSYNC_HINT);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    SetExitKey(KEY_NULL);

    gameUtils.CalcScale(1920, 1080);

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

/**
 * Unloads the game assets and cleans up the memory.
 *
 * @throws ErrorType An error occurred while unloading the assets.
 */
void GameLoop::Unload()
{
    // unload assets
    UnloadTexture(assetManager.Getlogo());
    UnloadFont(assetManager.GetFont());

    sceneManager.Unload();
    player.Unload();

    CloseWindow();
}

/**
 * Updates the game loop.
 */
void GameLoop::Update()
{
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    SetWindowSize(windowWidth, windowHeight);

    player.UpdatePlayer();
}

/**
 * Updates the game while it is paused.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void GameLoop::UpdateWhilePaused()
{
    gameUtils.UpdateDeltaTime();
    gameUtils.CalcScale(width, height);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
    sceneManager.SetWindowInfo(windowWidth, windowHeight);
    player.updatePlayerPersistance();
}

/**
 * DebugStatements is a function that displays debug information in the debug menu.
 * It checks the toggle state of the debug menu and if it is enabled, it retrieves the
 * frames per second (FPS), scale, screen height, screen width, delta time, and player
 * rectangle information. It then passes this information to the debug menu and draws
 * the items on the screen.
 *
 * @throws None
 */
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
        debug.PassItems("playerX: %d\n", player.GetplayerPosX());
        debug.DrawItems(3, 3, 16, 0, 2, RED);

        DrawRectangleLines(player.GetPlayerRect().x, player.GetPlayerRect().y, player.GetPlayerRect().width, player.GetPlayerRect().height, RED);
        DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), RED);
    }
}

/**
 * Draws the game scene.
 *
 * @throws ErrorType description of error
 */
void GameLoop::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    if (!isPaused)
    {
        // sceneManager.SplashScreen();
        // sceneManager.GameScreen();
        sceneManager.DrawScenes();
        // player.DrawPlayer();
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

/**
 * Helper function for the main game loop.
 *
 * @param userData a pointer to user-defined data
 *
 * @return void
 *
 * @throws None
 */
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

    if (gameLoop->isPaused)
    {
        if (IsKeyPressed(KEY_ONE))
        {
            ToggleFullscreen();
        }
    }

    gameLoop->UpdateWhilePaused();
    gameLoop->Draw();
}

/**
 * Runs the game loop.
 *
 * @throws ErrorType description of error
 */
void GameLoop::Run()
{
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop_arg(MainLoopHelper, this, 0, 1);
#else
    while (!WindowShouldClose())
    {
        MainLoopHelper(this);
    }

#endif
}
