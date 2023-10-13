#pragma once

#include "raylib.h"
#include <algorithm>
#include <string>


struct Bullets
{
    int x{};
    int y{};
    int width{};
    int height{};
    int ctr{};
    bool hasShot{};
    bool canShootAgain{};
    Rectangle rect;
};


class GameUtils
{
public:
    GameUtils();
    void CalcScale(int windowWidth, int windowHeight);
    Texture2D LoadImgFromFile(void *DATA, int WIDTH, int HEIGHT, int FORMAT);
    // Font LoadFontFromFile(int BASESIZE, int GLYPHCOUNT, int GLYPHPADDING, Texture2D TEXTURE, Rectangle *RECS, GlyphInfo *GLYPHS);
    Font LoadFontFromFile();
    void packTexture(const std::string &filePath, const std::string& outputFilename);
    void packFont(const std::string &filePath, const std::string& outputFilename);

    float GetScale() { return scale; };

    float GetDeltaTime()
    {
        return dt;
    }

    void UpdateDeltaTime();

    void UpdateWindowPos();

    int windowSizeW = GetScreenWidth();
    int windowSizeH = GetScreenHeight();

private:
    float dt{};
    int targetWidth{};
    int targetHeight{};

    int screenWidth{};
    int screenHeight{};

    float scaleX{};
    float scaleY{};

    float scale{};
};
