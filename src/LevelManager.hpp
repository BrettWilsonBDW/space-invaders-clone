#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Enemies.hpp"

class LevelManager
{
public:
    LevelManager();

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
    void Unload();
    void Update();
    void Draw();

private:
    Player *player;
    AssetManager *assetManager;
    GameUtils *gameUtils;
    Bullets *bullets;
    Enemies *enemiesArray;

    int enemiesArraySize{};
};