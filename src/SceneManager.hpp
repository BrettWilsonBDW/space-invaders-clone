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
    void PauseMenu();
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
    void Unload();
private:
    GameUtils* gameUtils;
    AssetManager* assetManager;
    int windowWidth;
    int windowHeight;
    // int pauseKeyState{};
    // bool pauseMenuState{};

    // bool isPaused{};
    
    Font font;
    
    Texture2D logo;
};