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

    levelOne.Init();
}

void LevelManager::Unload()
{
    levelOne.Unload();
}

void LevelManager::Update(float dt)
{
    levelOne.update(dt);



    if (levelOne.gameWinState)
    {
        nextLevelNum++;
        levelOne.gameWinState = false;
    }

    switch (nextLevelNum)
    {
    case 0:
        break;

    case 1:
        std::cout << nextLevelNum << std::endl;
        break;

    case 2:
        std::cout << nextLevelNum << std::endl;
        break;

    case 3:
        std::cout << nextLevelNum << std::endl;
        break;

    default:
        std::cout << "error in logic the level with number: " << nextLevelNum << " is not found" << std::endl;
        break;
    }
}

void LevelManager::Draw()
{
    levelOne.draw();
}
