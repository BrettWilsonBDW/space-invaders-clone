#pragma once

#include <iostream>
#include "../Enemies.hpp"
#include "raylib.h"
#include <algorithm>

class LevelBasic
{
public:
    LevelBasic();
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
    void update(float dt, int speed = 10, int bulletSpeed = 500);
    void Reset();
    void draw();

    bool gameWinState{};
    bool unloadToggle{};
    bool ignoreSpecialAbilities{};

private:
    int findLastEnemyArrayPos(int* array, int size);

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

    float timeWaited{};
};
