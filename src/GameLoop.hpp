#pragma once


#include "raylib.h"
#include "Debug.h"
#include "GameUtils.hpp"
#include "SceneManager.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

class GameLoop
{
public:
    GameLoop();
    void Init();
    void Update();
    void Draw();
    void DebugStatements();
    void Run();
    void Unload();
private:
    static void MainLoopHelper(void *userData);
    int windowWidth{};
    int windowHeight{};
    int width = 1920;
    int height = 1080;
    Debug debug;
    int useDebug{};
    GameUtils gameUtils;
    SceneManager gameScene;
    // Font font{LoadFont("assets/fonts/Roboto.ttf")};
    // Font font = LoadFontEx("path/to/font.ttf", 24, NULL, 0);

    Font font;


    Texture2D logo;
};