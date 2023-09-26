#pragma once

#include "raylib.h"
#include <algorithm>

class GameUtils
{
public:
    GameUtils();
    void CalcScale(int windowWidth, int windowHeight);
    float GetScale(){ return scale; };
private:

    int targetWidth{};
    int targetHeight{};

    int screenWidth{};
    int screenHeight{};

    float scaleX{};
    float scaleY{};

    float scale{};
};


