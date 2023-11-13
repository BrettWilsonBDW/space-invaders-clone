#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Enemies.hpp"
#include <iostream>

#include "levels/LevelBasic.hpp"

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
    void handleStats();
    void HandleStatsMenu(bool toggle);
    void Update(float dt);
    void Draw();

    int nextLevelNumPublic{};
    bool publicToggle{};

    bool playerCanMove{true};

private:
    Player *player;
    AssetManager *assetManager;
    GameUtils *gameUtils;
    Bullets *bullets;
    Enemies *enemiesArray;

    LevelBasic levels[7];

    int nextLevelNum{};

    bool toggleStatsMenu{};
    bool handleStatsToggle{true};

    int shootCtr{};

    std::string statsString{};
};
