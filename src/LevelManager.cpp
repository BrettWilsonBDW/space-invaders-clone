#include "LevelManager.hpp"
#include <iostream>

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    for (auto &level : levels)
    {
        level.SetPlayer(player);
        level.SetAssetManager(assetManager);
        level.SetGameUtils(gameUtils);
    }

    levels[0].SetEnemyAmt(5);
    levels[0].Init();

    levels[1].SetEnemyAmt(8);
    levels[1].Init();

    levels[2].SetEnemyAmt(5);
    levels[2].Init();

    levels[3].SetEnemyAmt(5);
    levels[3].Init(300, 300);
}

void LevelManager::Unload()
{
    for (auto &level : levels)
    {
        level.Unload();
    }
}

void LevelManager::Update(float dt)
{
    if (publicToggle)
    {
        nextLevelNum = nextLevelNumPublic;
    }

    if (levels[0].gameWinState || levels[1].gameWinState || (levels[2].gameWinState && levels[3].gameWinState))
    {
        nextLevelNum++;

        for (auto &level : levels)
        {
            level.gameWinState = false;
        }
    }

    switch (nextLevelNum)
    {
    case 0:
        levels[nextLevelNum].update(dt);
        break;

    case 1:
        levels[nextLevelNum].update(dt);
        // be mindful that this code unloads the previous level not the current one soo in this case level num 0 is the previous level
        levels[nextLevelNum - 1].unloadToggle = true;
        break;

    case 2:
        levels[nextLevelNum].update(dt);
        levels[nextLevelNum + 1].update(dt);
        levels[nextLevelNum - 1].unloadToggle = true;
        break;

    case 3:
        levels[nextLevelNum - 1].unloadToggle = true;
        levels[nextLevelNum].unloadToggle = true;
        break;

    case 4:
        break;

    default:
        std::cout << "error in logic the level with number: " << nextLevelNum << " is not found" << std::endl;
        break;
    }
}

void LevelManager::Draw()
{
    for (auto &level : levels)
    {
        level.draw();
    }
}
