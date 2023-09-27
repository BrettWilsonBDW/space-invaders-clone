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

    void UpdatePlayer();
    void playerControls();
    void DrawPlayer();
private:
    AssetManager* assetManager;
    GameUtils* gameUtils;
    // Texture2D ship{assetManager->GetShip()};
    Texture2D ship;

    int windowWidth{};
    int windowHeight{};

    int scale{};

    Vector2 playerVector{};
    Vector2 playerScreenPos{};

    // Vector2 playerScreenPos{static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};

};


