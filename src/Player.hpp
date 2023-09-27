#pragma once

#include "raylib.h"
#include "AssetManager.hpp"
#include "GameUtils.hpp"

class Player
{
public:
    Player();
    void SetAssetManager(AssetManager* assetManagerPass)
    {
        assetManager = assetManagerPass;
    }
    void SetGameUtils(GameUtils* gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }

    void Init();
    void Unload();

    void updatePlayerPersistance();

    void DrawPlayer();
private:
    AssetManager* assetManager;
    GameUtils* gameUtils;
    // Texture2D ship{assetManager->GetShip()};
    Texture2D ship;

    int windowWidth{};
    int windowHeight{};
};


