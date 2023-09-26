#pragma once

#include "raylib.h"
#include <algorithm>
#include <string>

class GameUtils
{
public:
    GameUtils();
    void CalcScale(int windowWidth, int windowHeight);
    Texture2D  LoadImgFromFile(void *DATA, int WIDTH, int HEIGHT, int FORMAT);
    void packTexture(const std::string &filePath, const std::string& outputFilename);

    float GetScale() { return scale; };

private:
    int targetWidth{};
    int targetHeight{};

    int screenWidth{};
    int screenHeight{};

    float scaleX{};
    float scaleY{};

    float scale{};
};
