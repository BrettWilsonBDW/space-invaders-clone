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
    Rectangle GetPlayerRect(){ return playerRect; };
    void updatePlayerPersistance();
    void UpdatePlayer();
    void playerControls();
    void DrawPlayer();
private:
    AssetManager* assetManager;
    GameUtils* gameUtils;
    Texture2D ship;
    
    int windowWidth{};
    int windowHeight{};
    int scale{};

    Rectangle playerRect{};
    Vector2 playerVector{};
    Vector2 playerScreenPos{};
};


