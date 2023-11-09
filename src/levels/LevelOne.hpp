#pragma once

#include <iostream>
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
    bool GetWinState()
    {
        return gameWinState;
    }
    void SetEnemyAmt(int amt)
    {
        enemyAmt = amt;
    }

    void Init(int x = 300, int y = 100);
    // void Init();
    void Unload();
    void update(float dt);
    void draw();

    bool gameWinState{};
    bool unloadToggle{};


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

    // bool gameWinState{};

    bool toggleWinCondition{true};

    int enemyAmt{};
};
