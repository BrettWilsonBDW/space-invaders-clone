#pragma once

#include "raylib.h"
#include "Debug.h"
#include "GameUtils.hpp"
#include "SceneManager.hpp"
#include "AssetManager.hpp"
#include "Player.hpp"
#include "Enemies.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

class GameLoop
{
public:
    GameLoop();
    void Init();
    void Update();
    void UpdateWhilePaused();
    void Draw();
    void DebugStatements();
    void Run();
    void Unload();
private:
    static void MainLoopHelper(void *userData);
    GameUtils gameUtils;
    SceneManager sceneManager;
    AssetManager assetManager;
    Debug debug;
    Player player;
    Enemies enemies;

    int windowWidth{};
    int windowHeight{};
    int width = 1920;
    int height = 1080;
    int useDebug{};

    bool isPaused{};
};