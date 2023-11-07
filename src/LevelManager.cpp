#include "LevelManager.hpp"
#include <iostream>

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    levelOne.SetPlayer(player);
    levelOne.SetAssetManager(assetManager);
    levelOne.SetGameUtils(gameUtils);

    levelOne.SetEnemyAmt(5);
    levelOne.Init();

    levelTwo.SetPlayer(player);
    levelTwo.SetAssetManager(assetManager);
    levelTwo.SetGameUtils(gameUtils);

    levelTwo.SetEnemyAmt(8);
    levelTwo.Init();

    levelThree.SetPlayer(player);
    levelThree.SetAssetManager(assetManager);
    levelThree.SetGameUtils(gameUtils);

    levelThree.SetEnemyAmt(5);
    levelThree.Init();

    levelThreeHalf.SetPlayer(player);
    levelThreeHalf.SetAssetManager(assetManager);
    levelThreeHalf.SetGameUtils(gameUtils);

    levelThreeHalf.SetEnemyAmt(5);
    levelThreeHalf.Init(300, 300);
}

void LevelManager::Unload()
{
    levelOne.Unload();
    levelTwo.Unload();
    levelThree.Unload();
    levelThreeHalf.Unload();
}

void LevelManager::Update(float dt)
{
    levelOne.update(dt);
    // levelTwo.update(dt);

    if (levelOne.gameWinState || levelTwo.gameWinState || levelThree.gameWinState)
    {
        nextLevelNum++;
        levelOne.gameWinState = false;
        levelTwo.gameWinState = false;
        levelThree.gameWinState = false;
    }

    switch (nextLevelNum)
    {
    case 0:
        break;

    case 1:
        levelTwo.update(dt);
        break;

    case 2:
        levelThree.update(dt);
        levelThreeHalf.update(dt);
        break;

    case 3:
        // std::cout << nextLevelNum << std::endl;
        break;

    default:
        std::cout << "error in logic the level with number: " << nextLevelNum << " is not found" << std::endl;
        break;
    }
}

void LevelManager::Draw()
{
    levelOne.draw();
    levelTwo.draw();
    levelThree.draw();
    levelThreeHalf.draw();
}
