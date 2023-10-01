#pragma once

#include "raylib.h"
#include "GameUtils.hpp"
#include "AssetManager.hpp"
#include <string>
#include "Player.hpp"

class SceneManager
{
public:
    SceneManager();
    void SplashScreen();
    void PauseMenu();
    void GameScreen();
    void SetGameUtils(GameUtils *gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }
    void SetAssetManager(AssetManager *assetManagerPass)
    {
        assetManager = assetManagerPass;
    }
    void SetPlayer(Player *playerPass)
    {
        player = playerPass;
    }
    void SetWindowInfo(int width, int height)
    {
        windowWidth = width;
        windowHeight = height;
    }
    void InitScenes();
    void Unload();

    void DrawScenes();
    int windowWidth;
    int windowHeight;

private:
    void DrawBackground();
    GameUtils *gameUtils;
    AssetManager *assetManager;
    Player *player;
    // int pauseKeyState{};
    // bool pauseMenuState{};

    // bool isPaused{};

    Font font;

    Texture2D logo;
    Texture2D background;

    // bool isPaused{};
};