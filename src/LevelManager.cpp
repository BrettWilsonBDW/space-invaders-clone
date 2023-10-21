#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    enemiesArraySize = 5;
    enemiesArray = new Enemies[enemiesArraySize];

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetPlayer(player);
        enemiesArray[i].SetAssetManager(assetManager);
        enemiesArray[i].SetGameUtils(gameUtils);

        enemiesArray[i].Init();

    }
}

void LevelManager::Unload()
{
    delete[] enemiesArray;
}

void LevelManager::Update()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        //TODO adjust placement logic
        enemiesArray[i].PostionPlacement(300 + i * 300, 300);
        enemiesArray[i].Update();
    }
}

void LevelManager::Draw()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].Draw();
    }
}
