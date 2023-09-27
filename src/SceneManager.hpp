#pragma once

#include "raylib.h"
#include "GameUtils.hpp"
#include <string>

class SceneManager
{
public:
    SceneManager();
    void SplashScreen();
    void SetGameUtils(GameUtils* gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }
    void SetWindowInfo(int width, int height)
    {
        windowWidth = width;
        windowHeight = height;
    }
    void SetFont(Font fontPass)
    {
        font = fontPass;
    }
    void SetImgData(Texture2D ImagePass)
    {
        logo = ImagePass;
    }
private:
    GameUtils* gameUtils;
    int windowWidth;
    int windowHeight;
    Font font;
    
    Texture2D logo;
};