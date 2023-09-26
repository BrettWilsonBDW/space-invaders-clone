#pragma once

#include "raylib.h"
#include "Debug.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif


class GameLoop {
public:
    GameLoop();
    void Init();
    void Update();
    void Draw();
    void Run();
private:
    static void MainLoopHelper(void* userData);
    int windowWidth{};
    int windowHeight{};
    Debug debug;
};