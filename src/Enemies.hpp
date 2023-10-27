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
    void CheckCollision();
    void PostionPlacement(int x, int y);
    void Shoot(bool shoot);
    void Movement();
    void Update();
    void Draw();

private:
    Player *player;
    AssetManager *assetManager;
    GameUtils *gameUtils;
    Bullets *bullets;
    Bullets enemyBullet{};

    Texture2D enemy1{};

    Rectangle enemiesRect{};

    Rectangle sourceRect{};
    Rectangle enemiesDestRect{};

    int enemyX{};
    int enemyY{};

    bool enemyIsActive{true};

    bool directionLR{};

    int maxBullets{};

    float scale{};
};
