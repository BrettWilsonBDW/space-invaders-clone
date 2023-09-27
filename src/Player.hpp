#pragma once

#include "raylib.h"
#include "AssetManager.hpp"

class Player
{
public:
    Player();
    void SetAssetManager(AssetManager* assetManagerPass)
    {
        assetManager = assetManagerPass;
    }

    void Init();
    void Unload();

    void updatePlayerPersistance();

    void DrawPlayer();
private:
    AssetManager* assetManager;
    // Texture2D ship{assetManager->GetShip()};
    Texture2D ship;

    int width{};
    int height{};
};


