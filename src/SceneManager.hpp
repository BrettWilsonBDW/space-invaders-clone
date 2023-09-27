#pragma once

#include "raylib.h"
#include "GameUtils.hpp"
#include "AssetManager.hpp"
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
    void SetAssetManager(AssetManager* assetManagerPass)
    {
        assetManager = assetManagerPass;
    }
    void SetWindowInfo(int width, int height)
    {
        windowWidth = width;
        windowHeight = height;
    }
    void InitScenes();
private:
    GameUtils* gameUtils;
    AssetManager* assetManager;
    int windowWidth;
    int windowHeight;
    
    Font font;
    
    Texture2D logo;
};