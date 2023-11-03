#pragma once

#include "iostream"
#include "../Enemies.hpp"
#include "raylib.h"
// #include "C:/Users/brend/Nextcloud/sources/repos/gamedev/raylibGames/space-invaders-clone/src/Enemies.hpp"

class LevelOne
{
public:
    LevelOne();
    void SetEnemiesArray(Enemies *enemiesArrayPass)
    {
        enemiesArray = enemiesArrayPass;
    }
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
    int GetRanNum()
    {
        return ranNum;
    }

    void Init();
    void Unload();
    void update(float dt);
    void draw();

private:
    Player *player;
    AssetManager *assetManager;
    GameUtils *gameUtils;
    Bullets *bullets;
    Enemies *enemiesArray;

    int enemiesArraySize{};

    float timePassed{};

    int ranNum{};

    float threshold{};

    int *enemyAliveArray{};
    int amtDead{};

    bool gameWinState{};
};
