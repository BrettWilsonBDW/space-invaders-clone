#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Player.hpp"
#include "AssetManager.hpp"
#include "GameUtils.hpp"

class Enemies
{
public:
    Enemies();
    void SetPlayer(Player *playerPass)
    {
        player = playerPass;
    }
    void SetAssetManager(AssetManager *assetManagerPass)
    {
        assetManager = assetManagerPass;
    }
    void SetGameUtils(GameUtils *gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }

    void Init();
    void Update();
    void CheckCollision();
    void Draw();

private:
    Player *player;
    AssetManager *assetManager;
    GameUtils *gameUtils;
    Bullets *bullets;

    Texture2D enemy1{};

    Rectangle enemiesRect{};

    Rectangle sourceRect{};
    Rectangle enemiesDestRect{};

    int maxBullets{};

    float scale{};
};
